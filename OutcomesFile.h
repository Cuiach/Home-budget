#ifndef OUTCOMESFILE_H
#define OUTCOMESFILE_H

#include <iostream>
#include <vector>
//#include <fstream>

#include "Markup.h"
#include "Operation.h"
#include "AdditionalMethods.h"
#include "DataFile.h"

using namespace std;

class OutcomesFile //:public OperationsFile::OperationsFile
{
    int lastOutcomeId = 0;

public:
//    OutcomesFile(string outcomesFileName) : DataFile(outcomesFileName) {};

    int getLastItemId();
    void addOutcomeToFile(Operation outcome);
    vector <Operation> readOutcomesFromFile(int idOfLoggedUser);
//    void readOutcomesFromFile(int dateFrom, dateTo);
};

#endif
