#include "File.h"
#include <sstream>

//Getter
string File::name() { return _name; };
string File::status() { return _status; };
int File::size() { return _size; };
pair<int, int> File::sectors() { return _sectors; };
string File::content() { return _content; }

string File::_toString(int level) {
	stringstream ss;
	const string space(level, '\t');

	ss << space << "- Name: " << _name << "\n";
	ss << space << " + Status: " << _status << "\n";
	ss << space << " + Sectors: " << _sectors.first << ", ... , " << _sectors.second;

	//Only print _size and _content when file is not a folder
	if ("Folder" != _status)
	{
		ss << "\n" << space << " + Size: " << _size;

	}

	//Only print _content when file extension is .txt
	int nameLength = _name.length();
	string extension = _name.substr(nameLength - 3, 3);	//3 = "txt".length()
	if ("txt" == extension || "TXT" == extension)
	{
		ss << "\n" << space << " + .txt content:\n";
		ss << space << "   " << _content;
	}

	return ss.str();
}

File::File()
{
	//do nothing
}


File::File(std::string name, std::string status, int size, std::pair<int, int> sectors, std::string content) {
	_name = name;
	_status = status;
	_size = size;
	_sectors = sectors;
	_content = content;
}


File::~File()
{
	//do nothing
}