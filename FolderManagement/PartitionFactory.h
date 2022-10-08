#pragma once
#include "Abstract_Format.h"
#include "FAT32_Format.h"
#include "NTFS_Format.h"


class PartitionFactory
{
private:
	Abstract_Format* type;

public:
	void read(LPCWSTR);

	PartitionFactory();
	~PartitionFactory();
	Abstract_Format* createPartition(int, LPCWSTR);
};

