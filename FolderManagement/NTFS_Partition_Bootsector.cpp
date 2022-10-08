#include "NTFS_Partition_Bootsector.h"
#include "Helper.h"
#include <sstream>


void NTFS_Partition_Bootsector::readSector(BYTE*& sector) {
	BPB.readSector(sector);
}


string NTFS_Partition_Bootsector::output() {
	stringstream ss;
	ss << "- Jump instruction to boot code: 0x" << hex << BS_jmpBoot << dec << endl;
	ss << "- Version/OS name: " << BS_OEMName << endl;
	ss << BPB.output() << endl;
	ss << "- End of sector marker: 0x" << hex << BS_endOfSectorMarker << endl;
	return ss.str();
}

NTFS_Partition_Bootsector::NTFS_Partition_Bootsector(){}

NTFS_Partition_Bootsector::NTFS_Partition_Bootsector(BYTE* sector) : Bootsector(sector) {
	readSector(sector);
}

NTFS_Partition_Bootsector::~NTFS_Partition_Bootsector(){}

