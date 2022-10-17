#include "Entry.h"
#include "SDET.h"
#include "Helper.h"
#include "ReadSector.h"
#include <sstream>

//Getter
vector<LongFilename> Entry::LFNs() { return _LFNs; }
string Entry::name() { return _name; }
int Entry::startCluster() { return _startCluster; };
int Entry::size() { return _size; };
File Entry::file() { return _file; };
SDET* Entry::sdet() { return _sdet; }

void Entry::_modulateName_noLFNs(BYTE*& entry) {
	stringstream builder;
	string buffer = toStringFromSector(entry, 0x00, 8);
	string extension = toStringFromSector(entry, 0x08, 3);
	size_t spacePos = 0;

	//If there are a space at the end of file name
	// => Get only the name before the space
	if ((spacePos = buffer.find(' ', 0)) != std::string::npos)
	{
		buffer = buffer.substr(0, spacePos);
	}

	//Get the file name
	builder << buffer;

	//If the file is archive => add '.' for extension
	if (0x20 == get_attribute())
	{
		builder << ".";
	}
	else {

		//clear space on extension
		if ((spacePos = extension.find(' ', 0)) != string::npos)
		{
			if (0 == spacePos)
			{
				extension = "";
			}
			else
			{
				extension = extension.substr(0, spacePos);
			}
		}

	}

	//extension is just a name;
	builder << extension;
	_name = builder.str();
}
void Entry::_modulateName_LFNs(BYTE*& entry) {

	std::stringstream builder;
	std::string  buffer;
	size_t nullPos;

	//If the entry does have LFNs
	int length = (int)_LFNs.size();

	//Get the name from LFN
	for (int i = length - 1; i >= 0; --i)
	{
		builder << _LFNs.at(i).name();
	}

	//get the name
	buffer = builder.str();

	//Get the only file + extension name behind NULL char
	if ((nullPos = buffer.find('\0', 0)) != std::string::npos)
	{
		buffer = buffer.substr(0, nullPos);
	}

	_name = buffer;
}


void Entry::_modulateName(BYTE*& entry) {

	//If the entry doesn't have LFNs
	if (0 == _LFNs.size()) {
		_modulateName_noLFNs(entry);
		return;
	}

	//else
	_modulateName_LFNs(entry);
}

void Entry::_getSDET() {

	//If the entry has a folder => get its SDEt
	if (0x10 == get_attribute())
	{
		_sdet = new SDET(_fat, _startCluster);
	}
}