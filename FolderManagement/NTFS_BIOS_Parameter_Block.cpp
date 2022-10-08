#include "NTFS_BIOS_Parameter_Block.h"
#include "Helper.h"
#include <sstream>


void NTFS_BIOS_Parameter_Block::readSector(BYTE*& sector) {
	BPB_BytsPerSec = hexToDec(sector, 0xB, 2);
	BPB_SecPerClus = hexToDec(sector, 0xD, 1);
	BPB_RsvdSecCnt = hexToDec(sector, 0xE, 2);
	BPB_Media = hexToDec(sector, 0x15, 1);
	BPB_SecPerTrk = hexToDec(sector, 0x18, 2);
	BPB_NumHeads = hexToDec(sector, 0x1A, 2);
	BPB_HiddSec = hexToDec(sector, 0x1C, 4);
	BPB_TotSec = hexToDec(sector, 0x28, 8);
	BPB_MFTStart = hexToDec(sector, 0x30, 4);
	BPB_MFTMirror = hexToDec(sector, 0x38, 8);

	BPB_MFTEntry = (int)pow(2, abs((int)(signed char)hexToDec(sector,0x40,1)));
	BPB_ClusPerBuffer = (int)pow(2, abs((int)(signed char)hexToDec(sector, 0x44, 1)));

	BPB_VolID = hexToDec(sector, 0x48, 8);
}


string NTFS_BIOS_Parameter_Block::output() {
	stringstream ss;
	ss << "- BIOS Paramenter Block (BPB)\n";
	ss << "\t Bytes per sector: " << BPB_BytsPerSec << endl;
	ss << "\t Sectors per cluster: " << BPB_SecPerClus << endl;
	ss << "\t Reversed: " << BPB_RsvdSecCnt << endl;
	ss << "\t Type of disk: " << BPB_Media << endl;
	ss << "\t Sectors per track: " << BPB_SecPerTrk << endl;
	ss << "\t Number of heads: " << BPB_NumHeads << endl;
	ss << "\t Total sectors of volume: " << BPB_TotSec << endl;
	ss << "\t MFT cluster index: " << BPB_MFTStart << endl;
	ss << "\t Mirrored MFT cluster index: " << BPB_MFTMirror << endl;
	ss << "\t Bytes per File Record Segment: " << BPB_MFTEntry << endl;
	ss << "\t Bytes per index buffer: " << BPB_ClusPerBuffer << endl;
	ss << "\t Volume serial number: 0x" << hex << BPB_VolID << endl;
	return ss.str();
}


NTFS_BIOS_Parameter_Block::NTFS_BIOS_Parameter_Block(){}

NTFS_BIOS_Parameter_Block::NTFS_BIOS_Parameter_Block(BYTE*& sector) {
	readSector(sector);
}

NTFS_BIOS_Parameter_Block::~NTFS_BIOS_Parameter_Block(){}

