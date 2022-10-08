#pragma once
#include <string>
#include <Windows.h>
#include <sstream>
#include <iostream>
#include <bitset>
using namespace std;

class FAT32_BIOS_Parameter_Block
{
private:
	int BPB_BytsPerSec;		//số bytes/sector
	int BPB_SecPerClus;		//số sectors/cluster
	int BPB_RsvdSecCnt;		//số sector trước bảng FAT
	int BPB_NumFATs;		//số bảng FAT
	int BPB_TotSec32;		//tổng số sector của volume
	const char* BPB_Media = "Fixed Disk"; //loại đĩa
	int BPB_FATSz32;		//số sector trong một bảng FAT
	int BPB_SecPerTrk;		//số sectors/track
	int BPB_NumHeads;		//số head
	int BPB_HiddSec;		//số sector ẩn
	int BPB_ExtFlags; 
	string BPB_FSVer;		//version FAT32
	int BPB_RootClus;		//chỉ số cluster đầu tiên của RDET
	int BPB_FSInfo;			//chỉ số sector chưa FSINFO - thông tin sector trống
	int BPB_BkBootSec;		//chỉ số sector chứa bản sao FAT32_BIOS_Parameter_Block
	int BPB_Reversed;		//dành riêng

public:
	FAT32_BIOS_Parameter_Block();
	FAT32_BIOS_Parameter_Block(BYTE*);
	~FAT32_BIOS_Parameter_Block();


	string output(); //in kết quả
	void readSector(BYTE*&);


};



