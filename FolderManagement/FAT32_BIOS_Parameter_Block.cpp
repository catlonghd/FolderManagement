#include "FAT32_BIOS_Parameter_Block.h"
#include "Helper.h"
#define _CRT_SECURE_NO_WARNINGS

void FAT32_BIOS_Parameter_Block::readSector(BYTE*& sector) {
	BPB_BytsPerSec = hexToDec(sector, 0xB, 2);
	BPB_SecPerClus = hexToDec(sector, 0xD, 1);
	BPB_RsvdSecCnt = hexToDec(sector, 0xE, 2);
	BPB_NumFATs = hexToDec(sector, 0x10, 1);
	BPB_TotSec32 = hexToDec(sector, 0x13, 2);
	BPB_FATSz32 = hexToDec(sector, 0x16, 2);
	BPB_SecPerTrk = hexToDec(sector, 0x18, 2);
	BPB_NumHeads = hexToDec(sector, 0x1A, 2);
	BPB_HiddSec = hexToDec(sector, 0x1C, 4);
	BPB_ExtFlags = hexToDec(sector, 0x28, 2);

	//lấy version FAT32
	int mijor = hexToDec(sector, 0x2A, 1);
	int minor = hexToDec(sector, 0x2B, 1);
	string version = "";
	version.append(to_string(mijor));
	version.append(".");
	version.append(to_string(minor));
	BPB_FSVer = version;

	BPB_RootClus = hexToDec(sector, 0x2C, 4);
	BPB_FSInfo = hexToDec(sector, 0x30, 2);
	BPB_BkBootSec = hexToDec(sector, 0x32, 2);
	BPB_Reversed = hexToDec(sector, 0x34, 12);
}


string FAT32_BIOS_Parameter_Block::output() {
	stringstream ss;
	ss << "- BIOS Paramenter Block (BPB)\n";
	ss << "\t Bytes per sector: " << BPB_BytsPerSec << endl;
	ss << "\t Sectors per cluster: " << BPB_SecPerClus << endl;
	ss << "\t Sectors before FAT: " << BPB_RsvdSecCnt << endl;
	ss << "\t Number of FAT: " << BPB_NumFATs << endl;
	ss << "\t Total sectors of volume: " << BPB_TotSec32 << endl;
	ss << "\t Type of disk: " << BPB_Media << endl;
	ss << "\t Sector per FAT: " << BPB_FATSz32 << endl;
	ss << "\t Sectors per track: " << BPB_SecPerTrk << endl;
	ss << "\t Number of heads: " << BPB_NumHeads << endl;
	ss << "\t Number of hidden sectors: " << BPB_HiddSec << endl;
	ss << "\t Flag: " << bitset<16>(BPB_ExtFlags) << endl;
	ss << "\t FAT32 version: " << BPB_FSVer << endl;
	ss << "\t RDET's first cluster index: " << BPB_RootClus << endl;
	ss << "\t FSINFO sector index: " << BPB_FSInfo << endl;
	ss << "\t Backup sector contains FAT32: " << BPB_BkBootSec << endl;
	ss << "\t Reversed: " << BPB_Reversed << endl;
	return ss.str();
}


FAT32_BIOS_Parameter_Block::FAT32_BIOS_Parameter_Block(){}

FAT32_BIOS_Parameter_Block::FAT32_BIOS_Parameter_Block(BYTE* sector) {
	readSector(sector);
}

FAT32_BIOS_Parameter_Block::~FAT32_BIOS_Parameter_Block(){
	if (BPB_Media) {
		delete[] BPB_Media;
		BPB_Media = NULL;
	}
}



