#include <windows.h>
#include "ReadSector.h"
#include <stdio.h>

int ReadSector::readSector(LPCWSTR  drive, int readPoint, BYTE* sector)
{
    if (this->readPoint != readPoint) {
        this->readPoint = readPoint;

        if (this->sector) {
            delete[] this->sector;
        }

        this->sector = new BYTE[this->readPoint];
    }


    int retCode = 0;
    DWORD bytesRead;
    HANDLE device = NULL;
    

    device = CreateFile(drive,    // Drive to open
        GENERIC_READ,           // Access mode
        FILE_SHARE_READ | FILE_SHARE_WRITE,        // Share Mode
        NULL,                   // Security Descriptor
        OPEN_EXISTING,          // How to create
        0,                      // File attributes
        NULL);                  // Handle to template

    if (device == INVALID_HANDLE_VALUE) // Open Error
    {
        printf("CreateFile: %u\n", GetLastError());
        CloseHandle(device);
        return 1;
    }

    SetFilePointer(device, readPoint, NULL, FILE_BEGIN);//Set a Point to Read

    if (!ReadFile(device, sector, 512, &bytesRead, NULL))
    {
        printf("ReadFile: %u\n", GetLastError());
        CloseHandle(device);
        return 2;
    }
    else
    {
        printf("Success!\n");
        CloseHandle(device);
    }

    return 0;
}


LPCWSTR ReadSector::getDrive() {
    return drive;
}
BYTE* ReadSector::getSector() {
    return sector;
}
int ReadSector::getReadPoint() {
    return readPoint;
}
void ReadSector::setDrive(LPCWSTR drive) {
    this->drive = drive;
}
void ReadSector::setReadPoint(int readPoint) {
    this->readPoint = readPoint;
    if (this->sector) {
        delete[] this->sector;
    }

    this->sector = new BYTE[this->readPoint];
}



ReadSector::ReadSector(){}
ReadSector::ReadSector(LPCWSTR drive, int readPoint, BYTE* sector) {
    this->readPoint = readPoint;
    this->sector = new BYTE[this->readPoint];

    if (!readSector(drive, readPoint, this->sector)) {
        this->drive = drive;
    }

}

ReadSector::~ReadSector() {
    if (sector) {
        delete[] sector;
        sector = NULL;
    }
}


int main(int argc, char ** argv)
{
    ReadSector a;
    BYTE* sector = new BYTE[BUFFER_SIZE];
    a.readSector(L"\\\\.\\E:", 0, sector);
    //ReadSector(L"\\\\.\\E:",0, sector);
    return 0;
}