#include "BudgetApp.h"

int BudgetApp::getLastDayOfMonth(int year, int month)
{
    int lastDayOfMonth = 0;

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        lastDayOfMonth = 31;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11))
    {
        lastDayOfMonth = 30;
    }
    else if ((month == 2) && (year % 4 == 0))
    {
        lastDayOfMonth = 29;
    }
    else if ((month == 2) && (year % 4 != 0))
    {
        lastDayOfMonth = 28;
    }

    return lastDayOfMonth;
}

void BudgetApp::addOutcome()
{
    flowManager->addOutcome();
}

void BudgetApp::addIncome()
{
    flowManager->addIncome();
}

void BudgetApp::printLastMonthInOut()
{
    int dateFrom = 0;
    int dateTo = 0;
    time_t temporaryTime = time(nullptr);
    tm *const timeToGetYearAndMonth = localtime(&temporaryTime);
    int year = 1900 + timeToGetYearAndMonth->tm_year;
    int month = timeToGetYearAndMonth->tm_mon + 1;
    if (month != 1)
    {

        dateFrom = year*10000 + (month-1)*100 + 1;
        dateTo = year*10000 + (month-1)*100 + getLastDayOfMonth(year, month);
  }
  else
  {
      dateFrom = (year-1)*10000 + 1201;
      dateFrom = (year-1)*10000 + 1231;
  }
    flowManager->printIncomesAndOutcomesOfRange(dateFrom, dateTo);
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
