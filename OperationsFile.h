#ifndef OPERATIONSFILE_H
#define OPERATIONSFILE_H

#include <iostream>
#include <vector>
//#include <fstream>

//#include "Markup.h"
#include "Operation.h"
//#include "AdditionalMethods.h"
#include "DataFile.h"
#include "OperationType.h"

using namespace std;

class OperationsFile //:public DataFile::DataFile
{
protected:
    const string FILE_NAME;
    int lastItemId = 0;
public:
    OperationsFile(string fileName) : FILE_NAME(fileName) {};

    int getLastItemId();
    void addOperationToFile(Operation operation, IOType ioType);
    vector <Operation> readOperationsFromFile(int idOfLoggedUser, IOType ioType);
};

#endif
