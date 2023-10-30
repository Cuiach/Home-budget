#include "DataFile.h"

string DataFile::getFileName()
    {
        return FILE_NAME;
    }

bool DataFile::isFileEmpty()
{
    bool emptyFile = true;
    fstream dataFile;
    dataFile.open(getFileName().c_str(), ios::app);

    if (dataFile.good() == true)
    {
        dataFile.seekg(0, ios::end);
        if (dataFile.tellg() != 0)
            emptyFile = false;
    }
    dataFile.close();
    return emptyFile;
}
