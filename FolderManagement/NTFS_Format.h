#pragma once
#include "Abstract_Format.h"
#include "NTFS_Partition_Bootsector.h"


class NTFS_Format : public Abstract_Format
{
private:
	NTFS_Partition_Bootsector* ntfs = NULL;

protected:
	void readPartition(LPCWSTR);

public:
	NTFS_Format();
	NTFS_Format(LPCWSTR);
	~NTFS_Format();
};

