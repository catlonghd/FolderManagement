#include "Helper.h"
#include "FAT32_Bootsector.h"

FAT32_BIOS_Parameter_Block FAT32_Bootsector::getBPB() { return BPB; };


void FAT32_Bootsector::readSector(BYTE*& sector){
	BPB.readSector(sector);
	BS_DrvNum = hexToDec(sector, 0x40, 1);
	BS_Reversed = hexToDec(sector, 0x41, 1);
	BS_BootSig = hexToDec(sector, 0x42, 1);
	BS_VolID = hexToDec(sector, 0x43, 4);
}

string FAT32_Bootsector::output(){
	stringstream ss;
	ss << "- Version/OS name: " << BS_OEMName << endl;
	ss << BPB.output() << endl;
	if (BS_DrvNum == 0x00)
		ss << "- Driver: " << "Floopy disks" << endl;
	else if(BS_DrvNum == 0x80)
		ss << "- Driver: " << "Hard disks" << endl;
	else 
	ss << "- Reversed: 0x" << hex << BS_Reversed << endl;
	ss << "- Boot signature: 0x" << BS_BootSig << endl;
	ss << "- Volume serial number: 0x" << BS_VolID << endl;
	ss << "- Volume label: " << BS_VolLab << endl;
	ss << "- FAT type: " << BS_FilSysType << endl;
	ss << "- End of sector marker: 0x" << BS_endOfSectorMarker << endl;

	return ss.str();
}


FAT32_Bootsector::FAT32_Bootsector(){}

FAT32_Bootsector::FAT32_Bootsector(BYTE* sector){
	readSector(sector);
}


FAT32_Bootsector::~FAT32_Bootsector(){}



