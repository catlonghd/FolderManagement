#pragma once
#include <Windows.h>
#include <stdio.h>

#define BUFFER_SIZE 512

class ReadSector {
private:
	LPCWSTR drive = L"";
	BYTE* sector = NULL;
	int readPoint;

public:
	int readSector(LPCWSTR, int, BYTE*);

	LPCWSTR getDrive();
	BYTE* getSector();
	int getReadPoint();
	void setDrive(LPCWSTR);
	void setReadPoint(int);


//Constructor and destructor
	ReadSector();
	ReadSector(LPCWSTR, int, BYTE*);
	~ReadSector();
};