#pragma once
#include <Windows.h>
#include <string>

using namespace std;
class NTFS_BIOS_Parameter_Block
{
private:
	int BPB_BytsPerSec;		//số bytes/sector
	int BPB_SecPerClus;		//số sectors/cluster
	int BPB_RsvdSecCnt;		//số sector trước bảng FAT
	int BPB_Media; //loại đĩa
	int BPB_SecPerTrk;		//số sectors/track
	int BPB_NumHeads;		//số head
	int BPB_HiddSec;		//số sector ẩn
	int BPB_TotSec;			//tổng số sector volume
	int BPB_MFTStart;		//cluster bắt đầu của MFT
	int BPB_MFTMirror;		//cluster bắt đầu của MFT dự phòng
	int BPB_MFTEntry;		//kích thước một bản ghi trong MFT, đơn vị là byte
	int BPB_ClusPerBuffer;	//số cluster của index buffer
	int BPB_VolID;			//volume serial number

public:
	NTFS_BIOS_Parameter_Block();
	NTFS_BIOS_Parameter_Block(BYTE*&);
	~NTFS_BIOS_Parameter_Block();


	string output();
	void readSector(BYTE*&);
};


	
