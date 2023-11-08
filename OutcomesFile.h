#ifndef OUTCOMESFILE_H
#define OUTCOMESFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Operation.h"
#include "AdditionalMethods.h"
#include "DataFile.h"
#include "OperationsFile.h"
#include "OperationType.h"

using namespace std;

class OutcomesFile :public OperationsFile::OperationsFile
{
    const IOType ioType = OUTCOME;

public:
    OutcomesFile(string outcomesFileName) : OperationsFile(outcomesFileName) {};

    int getLastItemId();
    void addOutcomeToFile(Operation outcome);
//    vector <Operation> readOutcomesFromFile(int idOfLoggedUser);
};

#endif
