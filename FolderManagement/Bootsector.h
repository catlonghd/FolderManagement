#pragma once
#include <string>
#include <Windows.h>
using namespace std;


class Bootsector
{
protected:
	int BS_jmpBoot;			//lệnh nhảy đến đoạn boot code
	string BS_OEMName;		//version/tên HĐH
	int BS_endOfSectorMarker;	//Dấu hiệu kết thúc bootsector

public:
	Bootsector();
	Bootsector(BYTE*);
	~Bootsector();

	string getOEMName();
	void readSector(BYTE*&);
};

