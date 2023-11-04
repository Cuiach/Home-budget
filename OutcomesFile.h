#ifndef OUTCOMESFILE_H
#define OUTCOMESFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Operation.h"
#include "AdditionalMethods.h"
#include "DataFile.h"

using namespace std;

class OutcomesFile //:public OperationsFile::OperationsFile - to piesn niedalekiej przyszlosci
{
    const string FILE_NAME;
    int lastOutcomeId = 0;

public:
    OutcomesFile(string outcomesFileName) : FILE_NAME(outcomesFileName) {};

    int getLastItemId();
    void addOutcomeToFile(Operation outcome);
    vector <Operation> readOutcomesFromFile(int idOfLoggedUser);
};

#endif
