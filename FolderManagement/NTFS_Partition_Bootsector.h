#pragma once
#include "NTFS_BIOS_Parameter_Block.h"
#include "Bootsector.h"

class NTFS_Partition_Bootsector : public Bootsector
{
private:
	NTFS_BIOS_Parameter_Block BPB; 
	
public:
	NTFS_Partition_Bootsector();
	NTFS_Partition_Bootsector(BYTE*);
	~NTFS_Partition_Bootsector();


	string output();
	void readSector(BYTE*& sector);
};

