#pragma once

#ifndef _FAT_H_
#define _FAT_H_
#include"FAT32_Bootsector.h"
#define CLUSTER_BYTE 4

class FAT {
private:
	int _FAT_size;						//Number of bytes in FAT
	LPCWSTR _drive;						//name of the drive which is used
	FAT32_Bootsector _bootSector;	//the boot sector
	BYTE* _data = nullptr;

	pair<int, int> _trace(int);
private:

	static bool isEOF(int);
private:
	void _initData();
public:		
	pair<int, int> trace(int);

	BYTE* data();
	int FAT_size();
	LPCWSTR drive();
	FAT32_Bootsector bootSector();
	void setBootSector(const FAT32_Bootsector&);
	void setDrive(const LPCWSTR&);	
public:		
	void initData();
public:
	FAT();
	FAT(FAT32_Bootsector, LPCWSTR);
	~FAT();
};

#endif _FAT_H_