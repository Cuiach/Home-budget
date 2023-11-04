#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Operation.h"
#include "AdditionalMethods.h"
#include "DataFile.h"

using namespace std;

class IncomesFile // :public OperationsFile::OperationsFile
{
    const string FILE_NAME;
    int lastItemId = 0;

public:
    IncomesFile(string incomesFileName) : FILE_NAME(incomesFileName) {};
    int getLastItemId();
    void addIncomeToFile(Operation income);
    vector <Operation> readIncomesFromFile(int idOfLoggedUser);
};

#endif
