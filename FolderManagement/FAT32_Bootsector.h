#pragma once
#include "FAT32_BIOS_Parameter_Block.h"
#include "Bootsector.h"
#include <string>

using namespace std;

class FAT32_Bootsector : public Bootsector{
private:
	FAT32_BIOS_Parameter_Block BPB;
	int BS_DrvNum;			//Ký hiệu vật lý đĩa
	int BS_Reversed;		//Dành riêng
	int BS_BootSig;			//ký hiệu nhận diện HĐH
	int BS_VolID;			//Volume serial number
	string BS_VolLab;		//Volume label
	string BS_FilSysType;	//Chuỗi nhận diện loại FAT
	int BS_endOfSectorMarker;	//Dấu hiệu kết thúc bootsector

public:

	FAT32_Bootsector();
	FAT32_Bootsector(BYTE*);
	~FAT32_Bootsector();

	string output();
	void readSector(BYTE*&);
};

