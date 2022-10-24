#include "FAT.h"
#include "ReadSector.h"
#include "Helper.h"
#define _CRT_SECURE_NO_WARNINGS

BYTE* FAT::data() { return _data; }
int FAT::FAT_size() { return _FAT_size; }
LPCWSTR FAT::drive() { return _drive; };
FAT32_Bootsector FAT::bootSector() { return _bootSector; };
void FAT::setBootSector(const FAT32_Bootsector& bootSector) { _bootSector = bootSector; };
void FAT::setDrive(const LPCWSTR& drive) { _drive = drive; };

pair<int, int> FAT::trace(int startClusterIndex) { return _trace(startClusterIndex); };

void FAT::initData() {

	//Delete while exist data 
	if (_data) {
		delete[]_data;
		_data = nullptr;
	}

	//Re-initialize
	_initData();
};

bool FAT::isEOF(int cluster) {
	const int EOFMask = 0xFFFFFFF0;	//Make a Mask to get the first digit
	int lastHalfByte = cluster & (~EOFMask);	//Get the first digit (and some dummy value from the second digit to seventh digit)
	return (lastHalfByte >= 0x8 && lastHalfByte <= 0xF);	//Return true if the first digit in range [0x8; 0xF]
}

pair<int, int> FAT::_trace(int startClusterIndex) {
	int endClusterIndex = startClusterIndex;
	int data = 0;

	//Iteration until data is EOF cluster
	do {
		data = hexToDec(_data, CLUSTER_BYTE * endClusterIndex, CLUSTER_BYTE);

		++endClusterIndex;
	} while (!isEOF(data));
	--endClusterIndex;

	//Get the start data sector
	int startDataSector = _bootSector.getBPB().getBPB_RsvdSecCnt()
		+ _bootSector.getBPB().getBPB_FATSz32() * _bootSector.getBPB().getBPB_BytsPerSec();

	//The name say all
	int sectorPerCluster = _bootSector.getBPB().getBPB_BytsPerSec();

	//Some easy formula to get start sector index and end sector index from
	//start cluster index and end cluster index
	int startSectorIndex = startDataSector + (startClusterIndex - 2) * sectorPerCluster;
	int endSectorIndex = startSectorIndex + (endClusterIndex - startClusterIndex) * sectorPerCluster + (sectorPerCluster - 1);

	return std::make_pair(startSectorIndex, endSectorIndex);
}



void FAT::_initData() {

	//Saved some already haved attributes from Boot Sector to local variables for faster execution
	//BIOSParameterBlock BPB = _bootSector.BPB();
	int sectorPerFat = _bootSector.getBPB().getBPB_FATSz32();
	int bytesPerSector = _bootSector.getBPB().getBPB_BytsPerSec();
	int sectorBeforeFAT = _bootSector.getBPB().getBPB_RsvdSecCnt();

	//Get the size of FAT
	_FAT_size = sectorPerFat * bytesPerSector;

	//Read the FAT sector
	ReadSector reader(_drive, sectorBeforeFAT, _FAT_size);
	/*
	reader.setDrive(_drive);
	reader.setNumberBytesRead(_FAT_size);
	reader.readSector(_drive, bytesPerSector * sectorBeforeFAT);*/

	//Save FAT data
	_data = new BYTE[_FAT_size + 2];
	memcpy(_data, reader.getSector(), sizeof(BYTE) * sectorPerFat * bytesPerSector);
}

FAT::FAT()
{
	//do nothing
}

FAT::FAT(FAT32_Bootsector bootSector, LPCWSTR drive) {

	//use swallow copy, because there are not any pointer in FAT32_VolumeBootRecord class
	_bootSector = bootSector;

	_drive = drive;
	_initData();
}

FAT::~FAT() {
	if (_data) {
		delete[]_data;
		_data = nullptr;
	}
}