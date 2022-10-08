#include "Helper.h"
#include <sstream>



int hexToDec(BYTE* sector, int offset, int len) {
	int result = 0;
	int coefficient = 1;
	int endPos = offset + len;
	for (int i = offset; i < endPos; i++) {
		result += (int)sector[i] * coefficient;
		coefficient *= 16 * 16;
	}

	return result;
}

string toStringFromSector(BYTE* sector, int offset, int len) {
	stringstream ss;
	int endPos = offset + len;
	for (int i = offset; i < endPos; i++) {
		ss << (unsigned char)sector[i];
	}

	return ss.str();
}

