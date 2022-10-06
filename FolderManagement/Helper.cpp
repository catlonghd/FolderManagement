#include "Helper.h"
#include <sstream>



int hexToDec(BYTE* sector, int offset, int len) {
	Helper h;
	int result = 0;
	int coefficient = 1;
	int endPos = offset + len;
	for (int i = offset; i < endPos; i++) {
		result = (int)sector[i] * coefficient;
		coefficient *= h.DEC * h.HEXA;
	}

	return result;
}

string toStringFromSector(BYTE* sector, int offset, int len) {
	stringstream ss;
	int endPos = offset + len;
	for (int i = offset; i < endPos; i++) {
		ss << sector[i];
	}

	return ss.str();
}

