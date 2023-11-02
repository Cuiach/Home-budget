#ifndef FLOWMANAGER_H
#define FLOWMANAGER_H

#include "AdditionalMethods.h"
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
    FlowManager (int idOfLoggedUser) : ID_OF_LOGGED_USER(idOfLoggedUser)
    {
        incomes = incomesFile.readIncomesFromFile(ID_OF_LOGGED_USER);
        outcomes = outcomesFile.readOutcomesFromFile(ID_OF_LOGGED_USER);
    };

    void addOutcome();
    void addIncome();
    void printAllIncomesAndOutcomes();
};


#endif
