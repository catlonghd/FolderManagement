#pragma once

{
private:
	int BS_DrvNum;			//Ký hiệu vật lý đĩa
	int BS_Reversed;		//Dành riêng
	int BS_BootSig;			//ký hiệu nhận diện HĐH
	int BS_VolID;			//Volume serial number
	string BS_VolLab;		//Volume label
	string BS_FilSysType;	//Chuỗi nhận diện loại FAT
	int BS_endOfSectorMarker;	//Dấu hiệu kết thúc bootsector

public:


	string output();
	void readSector(BYTE*&);
};

