#pragma once
#include <Windows.h>
#include <stdio.h>

#define BUFFER_SIZE 512

class ReadSector {
private:
	LPCWSTR drive = L"";
	BYTE* sector = NULL;
	int bytsRead;

public:
	int readSector(LPCWSTR, int, int);

	LPCWSTR getDrive();
	BYTE* getSector();
	int getBytsRead();
	void setDrive(LPCWSTR);
	void setReadPoint(int);


//Constructor and destructor
	ReadSector();
	ReadSector(LPCWSTR, int, int);
	~ReadSector();
};