#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include <ctime>
#include "UserManager.h"
#include "FlowManager.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;
    FlowManager *flowManager;

    const string INCOMES_FILE_NAME;
    const string OUTCOMES_FILE_NAME;

public:
    BudgetApp(string nameOfUsersFile, string nameOfIncomesFile, string nameOfOutcomesFile)
        : userManager(nameOfUsersFile), INCOMES_FILE_NAME(nameOfIncomesFile), OUTCOMES_FILE_NAME(nameOfOutcomesFile) {
        flowManager = NULL;
    };
    ~BudgetApp(){
        delete flowManager;
        flowManager = NULL;
    };
    void addOutcome();
    void addIncome();
    void printThisMonthInOut();
    void printLastMonthInOut();
    void printChosenRangeInOut();
    void printIO();
    void registerUser();
    void logIn();
    void logUserOut();
    void changePassword();
    bool isUserLogged();
};

#endif
