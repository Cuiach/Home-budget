#ifndef DATAFILE_H
#define DATAFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class DataFile
{
    const string FILE_NAME;

protected:
    DataFile(string fileName) : FILE_NAME(fileName) {}

    string getFileName();
    bool isFileEmpty();
};
#endif
