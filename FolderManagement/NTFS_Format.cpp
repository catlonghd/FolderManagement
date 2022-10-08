#include "NTFS_Format.h"
#include "ReadSector.h"
#include <iostream>

using namespace std;


void NTFS_Format::readPartition(LPCWSTR drive) {
	ReadSector rs(drive, 0, 512);

	ntfs = new NTFS_Partition_Bootsector(rs.getSector());

	cout << "---------------NTFS FORMATION----------------\n";
	cout << "-----------Partition Boot Sector----------------\n";
	cout << ntfs->output() << endl;
}


NTFS_Format::NTFS_Format(){}


NTFS_Format::NTFS_Format(LPCWSTR drive) {
	readPartition(drive);
}

NTFS_Format::~NTFS_Format(){}
