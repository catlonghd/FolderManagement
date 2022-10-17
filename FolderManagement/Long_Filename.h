#pragma once
#ifndef _LONG_FILENAME_H_
#define _LONG_FILENAME_H_
#include "Abstract_Entry.h"


class LongFilename : public Abstract_Entry {
private:
	string _name;

	void _modulateName(BYTE*&);
public:
	string name();

	LongFilename();
	LongFilename(BYTE*&);
	~LongFilename();
};

#endif // !_LONG_FILENAME_H_