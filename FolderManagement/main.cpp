#include "ReadSector.h"
#include "FAT32_Bootsector.h"
#include "NTFS_Partition_Bootsector.h"
#include "PartitionFactory.h"



void MENU() {
    wchar_t drive = 0;
    cout << "***INPUT drive you want to look up (Ex: If you want to look up E:\\ drive, input: E" << endl;
    cout << "Input the drive name: ";
    wcin >> drive;

    while (!((L'A' <= drive && drive <= L'Z') || (L'a' <= drive && drive <= L'z'))) {
        cout << "Invalid drive name, please input again\n";
        cout << "Input  the drive name: ";
        wcin >> drive;
    }

    PartitionFactory fac;
    wchar_t a[] = L"\\\\.\\X:";
    a[4] = drive;
    fac.read(a);
}




int main(int argc, char** argv)
{
    MENU();
    return 0;
}