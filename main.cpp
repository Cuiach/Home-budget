#include <iostream>
//#include <windows.h>
//#include <chrono>
//#include <ctime>
#include "date.h"
//#include "tz.h"

#include "BudgetApp.h"

#include "AdditionalMethods.h"

using namespace std;

//#include <iomanip>
//#include <ctime>

int main()
{
BudgetApp budgetApp("Users.xml");
char choice;

while (true)
{
    if (budgetApp.isUserLogged() == 0)
    {
        choice = AdditionalMethods::chooseOptionFromMainMenu();

        switch (choice)
        {
        case '1': budgetApp.registerUser(); break;
        case '2': budgetApp.logIn(); break;
        case '9': exit(0); break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }
    else
    {
        choice = AdditionalMethods::chooseOptionFromLoggedUserMenu();

        switch (choice)
        {
        case '1': budgetApp.addIncome(); break;
        case '2': budgetApp.addOutcome(); break;
        case '3': budgetApp.printThisMonthInOut(); break;
        case '4': budgetApp.printLastMonthInOut(); break;
        case '5': budgetApp.printChosenRangeInOut(); break;
        case '6': budgetApp.changePassword(); break;
        case '7': budgetApp.logUserOut(); break;
        }
    }
}

return 0;
}
