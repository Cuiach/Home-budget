#ifndef OPERATIONSFILE_H
#define OPERATIONSFILE_H

#include <iostream>
#include <vector>
//#include <fstream>

#include "Markup.h"
#include "Operation.h"
#include "AdditionalMethods.h"
#include "DataFile.h"
#include "OperationType.h"

using namespace std;

class OperationsFile :public DataFile
{
    int lastItemId = 0;
    string getOperationTypeName(IOType ioType);
public:
    OperationsFile(string fileName) : DataFile(fileName) {};
    int getLastItemId();
    void addOperationToFile(Operation operation, IOType ioType);
    vector <Operation> readOperationsFromFile(int idOfLoggedUser, IOType ioType);
};

#endif
