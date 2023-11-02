#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "FlowManager.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;
    FlowManager *flowManager;

public:
    BudgetApp(string nameOfUsersFile) : userManager(nameOfUsersFile)  {
        flowManager = NULL;
    };
    ~BudgetApp(){
    };
    void addOutcome();
    void addIncome();
    void printInOut();
    void registerUser();
    void wypiszWszystkichUzytkownikow();
    void logIn();
    void logUserOut();
    void changePassword();
    bool isUserLogged();
};

#endif
