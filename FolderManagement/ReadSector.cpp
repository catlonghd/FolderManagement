#include <windows.h>
#include "ReadSector.h"
#include <stdio.h>

int ReadSector::readSector(LPCWSTR drive, int readPoint, int bytsRead)
{
    if (this->bytsRead != bytsRead) {
        this->bytsRead = bytsRead;

        if (this->sector) {
            delete[] this->sector;
        }

        this->sector = new BYTE[this->bytsRead];
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
        //CloseHandle(device);
        return 1;
    }

    SetFilePointer(device, readPoint, NULL, FILE_BEGIN);//Set a Point to Read

    if (!ReadFile(device, this->sector, BUFFER_SIZE, &bytesRead, NULL))
    {
        printf("ReadFile: %u\n", GetLastError());
        return 2;
    }
    else
    {
        //printf("Success!\n");
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
int ReadSector::getBytsRead() {
    return bytsRead;
}
void ReadSector::setDrive(LPCWSTR drive) {
    this->drive = drive;
}
void ReadSector::setReadPoint(int readPoint) {
    this->bytsRead = readPoint;
    if (this->sector) {
        delete[] this->sector;
    }

    this->sector = new BYTE[this->bytsRead];
}



ReadSector::ReadSector(){}
ReadSector::ReadSector(LPCWSTR drive, int readPoint, int bytsRead) {
    this->bytsRead = bytsRead;
    this->sector = new BYTE[this->bytsRead];

    if (!readSector(drive, readPoint, bytsRead)) {
        this->drive = drive;
    }

}

ReadSector::~ReadSector() {
    if (sector) {
        delete[] sector;
        sector = NULL;
    }
}


