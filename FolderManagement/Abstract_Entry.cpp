#include"Abstract_Entry.h"
#include"Helper.h"
#define _CRT_SECURE_NO_WARNINGS

int Abstract_Entry::get_attribute() { return attribute; };
const int Abstract_Entry::get_bytesPerEntry() { return bytesPerEntry; };
Abstract_Entry::Abstract_Entry()
{
	//do nothing
}

Abstract_Entry::Abstract_Entry(BYTE*& entry) {
	firstByte = hexToDec(entry, 0x0, 1);
	attribute = hexToDec(entry, 0xB, 1);
}

Abstract_Entry::~Abstract_Entry()
{
	//do nothing
}