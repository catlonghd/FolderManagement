#include "PartitionFactory.h"
#include "ReadSector.h"
#include "Bootsector.h"
#include <exception>

Abstract_Format* PartitionFactory::createPartition(int type, LPCWSTR drive) {
	Abstract_Format* obj = NULL;
	switch (type) {
	case 1:
		obj = new FAT32_Format(drive);
		break;
	case 2:
		obj = new NTFS_Format(drive);
		break;
	}

	return obj;
}

void PartitionFactory::read(LPCWSTR drive) {
	ReadSector rs(drive, 0, 512);
	
	Bootsector bs(rs.getSector());

	try {
		if (bs.getOEMName().find("NTFS", 0) == string::npos) {
			type = createPartition(1, drive);
		}
		else {
			type = createPartition(2, drive);
		}
	}
	catch (const exception e) {
		//std::cout << "Doesn't exist this drive !\n";
		std::cout << e.what() << "\n";
	}
	
}


PartitionFactory::PartitionFactory(){}

PartitionFactory::~PartitionFactory(){
	delete type;
}

