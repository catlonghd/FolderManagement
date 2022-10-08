#pragma once
#include "FAT32_Bootsector.h"
#include "Abstract_Format.h"


class FAT32_Format : public Abstract_Format
{
private:
	FAT32_Bootsector* f32 = NULL;

protected:
	void readPartition(LPCWSTR);

public:
	FAT32_Format();
	FAT32_Format(LPCWSTR);
	~FAT32_Format();
};
