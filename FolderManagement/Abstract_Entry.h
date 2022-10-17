#pragma once

#ifndef _ABSTRACT_ENTRY_H_
#define _ABSTRACT_ENTRY_H_
#include<string>
#include<Windows.h>
using namespace std;

class Abstract_Entry {
private:
	static const int bytesPerEntry = 32;
	int firstByte;
	int attribute;

public:
	int get_attribute();
	static const int get_bytesPerEntry();
	Abstract_Entry();
	Abstract_Entry(BYTE*&);
	virtual ~Abstract_Entry();
};


#endif // !_ABSTRACT_ENTRY_H_

