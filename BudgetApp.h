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

    int getLastDayOfMonth(int year, int month);
    int getCurrentYearMonth();

public:
    BudgetApp(string nameOfUsersFile) : userManager(nameOfUsersFile)  {
        flowManager = NULL;
    };
    ~BudgetApp(){
    };
    void addOutcome();
    void addIncome();
    void printThisMonthInOut();
    void printLastMonthInOut();
    void printChosenRangeInOut();
    void printInOut();
    void registerUser();
    void logIn();
    void logUserOut();
    void changePassword();
    bool isUserLogged();
};

#endif
