#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
//#include <fstream>

#include "Markup.h"
#include "Operation.h"
#include "AdditionalMethods.h"
#include "DataFile.h"

using namespace std;

class IncomesFile //:public OperationsFile::OperationsFile
{
    int lastItemId = 0;

public:
//    IncomesFile(string incomesFileName) : DataFile(incomesFileName) {};
    int getLastItemId();
    void addIncomeToFile(Operation income);
    vector <Operation> readIncomesFromFile(int idOfLoggedUser);
//    void readIncomesFromFile(int dateFrom, dateTo);
};

#endif
