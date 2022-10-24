#pragma once
#ifndef _RDET_H_
#define _RDET_H_

#include <vector>
#include "FAT.h"
#include "Entry.h"

class RDET {
protected:
	int _clusterNumber;

	int _size;
	FAT* _fat = nullptr;
	BYTE* _data = nullptr;
	vector<Entry*> _entries;

	int size();
	//virtual int _getClusterNumber();
	void _getAllEntries();
	void _readData();
	string _toString(int level = 0);
public:
	FAT* fat();
	BYTE* data();
	vector<Entry*> entries();

	RDET();
	RDET(FAT*, int _clusterNumber);
	virtual ~RDET();
};


#endif // !_RDET_H_
