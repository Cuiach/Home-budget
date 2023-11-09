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
    string getOperationTypeName(OperationType ioType);
public:
    OperationsFile(string fileName) : DataFile(fileName) {};
    void addOperationToFile(Operation operation, OperationType ioType);
    vector <Operation> readOperationsFromFile(int idOfLoggedUser, OperationType ioType);
};

#endif
