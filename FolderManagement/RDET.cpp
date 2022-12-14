#include "RDET.h"
#include "ReadSector.h"
#include <sstream>

//Getter
int RDET::size() { return _size; }
FAT* RDET::fat() { return _fat; };
BYTE* RDET::data() { return _data; };
vector<Entry*> RDET::entries() { return _entries; };

void RDET::_getAllEntries() {
	int entry = _size / Abstract_Entry::get_bytesPerEntry();
	for (int i = 0; i < entry; ++i) {
		BYTE* buffer = _data + (Abstract_Entry::get_bytesPerEntry() * i);

		//If there is an empty entry => end;
		if (0x00 == buffer[0]) break;

		//If there isn't a deleted entry or dot entry (for SDET super constructor)
		if (0xE5 != buffer[0] && 0x2E != buffer[0]) {
			if (0x0F == buffer[0xB] || 0x10 == buffer[0xB] || 0x20 == buffer[0xB]) {
				std::vector<LongFilename> LFNs;
				//if the entry is LFN => get all the LFNs next to it
				while (0x0F == buffer[0xB]) {
					LFNs.push_back(LongFilename(buffer));
					++i;
					buffer = _data + (Abstract_Entry::get_bytesPerEntry() * i);
				}

				_entries.push_back(new Entry());
				LFNs.clear();
			}
		}
	}
}

void RDET::_readData() {

	//Get the [start; end] sector of RDET
	pair<int, int> sectors = _fat->trace(_clusterNumber);

	//Number of bytes to read
	_size = (sectors.second - sectors.first + 1) * _fat->bootSector().getBPB().getBPB_BytsPerSec();

	//Read all bytes from [start; end] sector of RDET
	ReadSector reader(_fat->drive(), sectors.first, _size);

	//allocate memory for _data
	_data = new BYTE[_size + 2];

	//_data = reader.sector();
	memcpy(_data, reader.getSector(), _size * sizeof(BYTE));

	//get entries
	_getAllEntries();
}



RDET::RDET()
{
	//do nothing
}

RDET::RDET(FAT* fat, int clusterNumber) {
	_clusterNumber = clusterNumber;
	_fat = fat;
	_readData();
}

RDET::~RDET() {
	if (_data) {
		delete[]_data;
		_data = nullptr;
	}

	int size = _entries.size();
	for (int i = 0; i < size; ++i) {
		if (_entries[i])
		{
			delete _entries[i];
		}
	}
	//do nothing
}

