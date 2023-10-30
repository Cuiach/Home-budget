#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;

public:
    BudgetApp(string nameOfUsersFile) : userManager(nameOfUsersFile) {
    };
    ~BudgetApp(){
    };
    void registerUser();
    void wypiszWszystkichUzytkownikow();
    void logIn();
    void logUserOut();
    void changePassword();
    bool isUserLogged();
};

#endif
