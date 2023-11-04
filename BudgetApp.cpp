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
    int dateFrom = 0;
    int dateTo = 0;
    int year = AdditionalMethods::convertStringToInt((AdditionalMethods::convertIntToString(AdditionalMethods::getCurrentYearMonthDay()).substr(0,4)));
    int month = AdditionalMethods::convertStringToInt((AdditionalMethods::convertIntToString(AdditionalMethods::getCurrentYearMonthDay()).substr(4,2)));

    dateFrom = year*10000 + (month)*100 + 1;
    dateTo = year*10000 + (month)*100 + AdditionalMethods::getLastDayOfMonth(year, month);

    flowManager->printIncomesAndOutcomesOfRange(dateFrom, dateTo);
}

void BudgetApp::printLastMonthInOut()
{
    int dateFrom = 0;
    int dateTo = 0;
    int year = AdditionalMethods::convertStringToInt((AdditionalMethods::convertIntToString(AdditionalMethods::getCurrentYearMonthDay()).substr(0,4)));
    int month = AdditionalMethods::convertStringToInt((AdditionalMethods::convertIntToString(AdditionalMethods::getCurrentYearMonthDay()).substr(4,2)));

    if (month != 1)
    {
        month = month -1;
        dateFrom = year*10000 + (month)*100 + 1;
        dateTo = year*10000 + (month)*100 + AdditionalMethods::getLastDayOfMonth(year, month);
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
