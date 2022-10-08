#include "Bootsector.h"
#include "Helper.h"
#include <sstream>


string Bootsector::getOEMName() {
	return BS_OEMName;
}

void Bootsector::readSector(BYTE*& sector) {
	BS_jmpBoot = hexToDec(sector, 0x0, 3);
	BS_OEMName = toStringFromSector(sector, 0x3, 8);
	BS_endOfSectorMarker = hexToDec(sector, 0x1FE, 2);
}


Bootsector::Bootsector(){}

Bootsector::Bootsector(BYTE* sector) {
	readSector(sector);
}

Bootsector::~Bootsector(){}



