#ifndef DATAFILE_H
#define DATAFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class DataFile
{
    const string FILE_NAME;
protected:
    int lastId;

    DataFile(string fileName) : FILE_NAME(fileName)
    {
        lastId = 0;
    }

    string getFileName();

public:
    int getLastId();
};
#endif
