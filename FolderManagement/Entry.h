#pragma once
#ifndef _ENTRY_H_
#define _ENTRY_H_

#include "FAT.h"
#include "Abstract_Entry.h"
#include "Long_Filename.h"
#include "File.h"
#include <vector>

class SDET;

class Entry : public Abstract_Entry {
private:
	FAT* _fat;
	std::vector<LongFilename> _LFNs;
	std::string _name;
	int _startCluster;
	int _size;

	File _file;
	SDET* _sdet;

	int _getStartCluster(BYTE*&);
	void _getSDET();
	void _getFile();
	void _modulateName_noLFNs(BYTE*&);
	void _modulateName_LFNs(BYTE*&);
	void _modulateName(BYTE*&);
	void _readEntry(BYTE*&);
	string _toString(int level);
public:		//Getter
	vector<LongFilename> LFNs();
	string name();
	int startCluster();
	int size();

	File file();
	SDET* sdet();
};

#endif // !_ENTRY_H_