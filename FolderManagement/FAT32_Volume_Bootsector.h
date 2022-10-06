#pragma once
#include "BIOS_Parameter_Block.h"

class FAT32_Volume_Bootsector
{
private:
	int BS_jmpBoot;			//lệnh nhảy đến đoạn boot code
	string BS_OEMName;		//version/tên HĐH
	BIOS_Parameter_Block BPB;
	int BS_DrvNum;			//Ký hiệu vật lý đĩa
	int BS_Reversed;		//Dành riêng
	int BS_BootSig;			//ký hiệu nhận diện HĐH
	int BS_VolID;			//Volume serial number
	string BS_VolLab;		//Volume label
	string BS_FilSysType;	//Chuỗi nhận diện loại FAT
	int BS_endOfSectorMarker;	//Dấu hiệu kết thúc bootsector

public:
	FAT32_Volume_Bootsector();
	FAT32_Volume_Bootsector(BYTE*&);
	~FAT32_Volume_Bootsector();


	string output();
	void readSector(BYTE*&);
};

