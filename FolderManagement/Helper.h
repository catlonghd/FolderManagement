#pragma once
#include <Windows.h>
#include <string>
using namespace std;

struct Helper
{
	const int HEXA = 16;
	const int DEC = 10;
};

int hexToDec(BYTE*, int, int);
string toStringFromSector(BYTE*, int, int);

