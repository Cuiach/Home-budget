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

int BudgetApp::getCurrentYearMonth()
{
    time_t temporaryTime = time(nullptr);
    tm *const timeToGetYearAndMonth = localtime(&temporaryTime);
    int year = 1900 + timeToGetYearAndMonth->tm_year;
    int month = timeToGetYearAndMonth->tm_mon + 1;
    return year*100 + month;
}

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
    int dateFrom = 0;
    int dateTo = 0;
    int year = AdditionalMethods::convertStringToInt((AdditionalMethods::convertIntToString(getCurrentYearMonth()).substr(0,4)));
    int month = AdditionalMethods::convertStringToInt((AdditionalMethods::convertIntToString(getCurrentYearMonth()).substr(4,2)));

    dateFrom = year*10000 + (month)*100 + 1;
    dateTo = year*10000 + (month)*100 + getLastDayOfMonth(year, month);

    flowManager->printIncomesAndOutcomesOfRange(dateFrom, dateTo);
}

void BudgetApp::printLastMonthInOut()
{
    int dateFrom = 0;
    int dateTo = 0;
    int year = AdditionalMethods::convertStringToInt((AdditionalMethods::convertIntToString(getCurrentYearMonth()).substr(0,4)));
    int month = AdditionalMethods::convertStringToInt((AdditionalMethods::convertIntToString(getCurrentYearMonth()).substr(4,2)));

    if (month != 1)
    {
        month = month -1;
        dateFrom = year*10000 + (month)*100 + 1;
        dateTo = year*10000 + (month)*100 + getLastDayOfMonth(year, month);
    }
    else
    {
      dateFrom = (year-1)*10000 + 1201;
      dateFrom = (year-1)*10000 + 1231;
    }

    flowManager->printIncomesAndOutcomesOfRange(dateFrom, dateTo);
}

void BudgetApp::printChosenRangeInOut()
{
    int dateFrom = 0;
    int dateTo = 0;
    int excludeFirstOccurence = 0;

    do {
        if (excludeFirstOccurence != 0)
        {
            cout << endl << " Data konca musi byc po dacie poczatku. Sprobuj jeszcze raz";
        }

        cout << endl << " Wpisz date poczatku obliczenia bilansu: ";
        dateFrom = AdditionalMethods::getDateAndConvertToInt();
        cout << endl << " Wpisz date konca obliczenia bilansu: ";
        dateTo = AdditionalMethods::getDateAndConvertToInt();

        ++excludeFirstOccurence;

    } while (dateFrom > dateTo);

    flowManager->printIncomesAndOutcomesOfRange(dateFrom, dateTo);
}

void BudgetApp::printIO()
{
    flowManager->printIO();
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
