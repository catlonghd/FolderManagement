#pragma once
#include <Windows.h>

class Abstract_Format
{
public:
	virtual void readPartition(LPCWSTR) = 0;

public:
	Abstract_Format(){};
	virtual ~Abstract_Format(){};
};


