#pragma once
#ifndef _FILE_H_
#define _FILE_H_
using namespace std;
#include <string>

class File {
protected:
	string _name;
	string _status;
	int _size;
	pair<int, int> _sectors;
	string _content;
private:
//Example: C:/ have 2 folder: a and b
	//a is empty; b has file test.txt;
	//	=> level(a) = 0
	//	=> level(b) = 0
	//		=>> level(test.txt) = 1
	// level is the number of folders before of a file/folder
	virtual string _toString(int level) final;

public:	//getter
	virtual string name() final;
	virtual string status() final;
	virtual int size() final;
	virtual pair<int, int> sectors() final;
	virtual string content();

public:	//constructor/destructor
	File();
	File(string, string, int, pair<int, int>,string content = "");
	virtual ~File();
};


#endif // !_FILE_H_