#include "BudgetApp.h"

void BudgetApp::logUserOut()
{
    userManager.logUserOut();
}

void BudgetApp::registerUser()
{
    userManager.registerUser();
}

void BudgetApp::logIn()
{
    userManager.logUserIn();
    if (userManager.isUserLoggedIn())
    {
        int testIntIdLoggedUser = userManager.getIdOfLoggedUser();
    }
}

void BudgetApp::changePassword()
{
    userManager.changePasswordOfLoggedUser();
}

bool BudgetApp::isUserLogged()
{
    return userManager.isUserLoggedIn();
}
