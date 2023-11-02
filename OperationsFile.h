#ifndef OPERATIONSFILE_H
#define OPERATIONSFILE_H

#include <iostream>
//#include <vector>
//#include <fstream>

//#include "Markup.h"
#include "Operation.h"
//#include "AdditionalMethods.h"
#include "DataFile.h"

using namespace std;

class OperationsFile :public DataFile::DataFile
{

public:
    OperationsFile(string fileName) : DataFile(fileName) {};

    void addOperationToFile(Operation operation);
//    void readOperationsFromFile(int dateFrom, dateTo);
};

#endif
