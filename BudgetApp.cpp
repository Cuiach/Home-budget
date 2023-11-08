#include "BudgetApp.h"

void BudgetApp::addOutcome()
{
    flowManager->addOutcome();
}

void BudgetApp::addIncome()
{
    flowManager->addIncome();
}

void BudgetApp::printThisMonthInOut()
{
    flowManager->printThisMonthInOut();
}

void BudgetApp::printLastMonthInOut()
{
    flowManager->printLastMonthInOut();
}

void BudgetApp::printChosenRangeInOut()
{
    flowManager->printChosenRangeInOut();
}

void BudgetApp::logUserOut()
{
    userManager.logUserOut();
    delete flowManager;
    flowManager = NULL;
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
        flowManager = new FlowManager(INCOMES_FILE_NAME, OUTCOMES_FILE_NAME, userManager.getIdOfLoggedUser());
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
