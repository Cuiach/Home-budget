#ifndef FLOWMANAGER_H
#define FLOWMANAGER_H

#include "AdditionalMethods.h"
#include "DateMethods.h"
#include "Operation.h"
#include "IncomesFile.h"
#include "OutcomesFile.h"

using namespace std;

class FlowManager
{
    IncomesFile incomesFile;
    OutcomesFile outcomesFile;
    const int ID_OF_LOGGED_USER;
    vector <Operation> incomes;
    vector <Operation> outcomes;

    Operation getOperationDetails();

public:
    FlowManager (string incomesFileName, string outcomesFileName, int idOfLoggedUser) : incomesFile(incomesFileName), outcomesFile(outcomesFileName), ID_OF_LOGGED_USER(idOfLoggedUser)
    {
        outcomes = outcomesFile.readOutcomesFromFile(ID_OF_LOGGED_USER);
        incomes = incomesFile.readIncomesFromFile(ID_OF_LOGGED_USER);
    };

    void addOutcome();
    void addIncome();
    void printIncomesAndOutcomesOfRange(int dateFrom, int dateTo);
    void printIO();
};


#endif
