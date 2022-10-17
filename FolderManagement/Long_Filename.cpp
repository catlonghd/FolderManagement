#include "Long_Filename.h"
#include <sstream>

//Getter
string LongFilename::name() { return _name; }

void LongFilename::_modulateName(BYTE*& entry) {
	stringstream builder;
	for (int i = 0x01; i < 0x0B; i += 2) { builder << (unsigned char)entry[i]; }
	for (int i = 0x0E; i < 0x1A; i += 2) { builder << (unsigned char)entry[i]; }
	for (int i = 0x1c; i < 0x20; i += 2) { builder << (unsigned char)entry[i]; }
	_name = builder.str();
}

LongFilename::LongFilename() : Abstract_Entry()
{
	//do nothing
}

LongFilename::LongFilename(BYTE*& entry) : Abstract_Entry(entry)
{
	_modulateName(entry);
}

LongFilename::~LongFilename()
{
	//do nothing
}