#include "BudgetApp.h"

void BudgetApp::addOutcome()
{
    flowManager->addOutcome();
}

void BudgetApp::addIncome()
{
    flowManager->addIncome();
}

void BudgetApp::printInOut()
{
    flowManager->printAllIncomesAndOutcomes();
}

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
/*usunac*/        int testIntIdLoggedUser = userManager.getIdOfLoggedUser();
        flowManager = new FlowManager(userManager.getIdOfLoggedUser());
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
