#include "FAT32_Format.h"
#include "ReadSector.h"
#include <iostream>
using namespace std;


void FAT32_Format::readPartition(LPCWSTR drive) {
	ReadSector rs(drive, 0, 512);

	f32 = new FAT32_Bootsector(rs.getSector());

	cout << "----------FAT32 FORMATION----------------\n";
	cout << "------------Boot Sector----------------\n";
	cout << f32->output() << endl;
	
}


FAT32_Format::FAT32_Format(){}

FAT32_Format::FAT32_Format(LPCWSTR drive) {
	readPartition(drive);
}

FAT32_Format::~FAT32_Format(){}



