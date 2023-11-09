#include <iostream>
#include "date.h"
#include "BudgetApp.h"
#include "AdditionalMethods.h"
#include "Menus.h"
#include "OperationType.h"
#include "FlowManager.h"
#include "OperationsFile.h"
#include "UserManager.h"

using namespace std;

int main()
{
    BudgetApp budgetApp("Users.xml", "Incomes.xml", "Outcomes.xml");
    char choice;

    while (true)
    {
        if (budgetApp.isUserLogged() == 0)
        {
            choice = Menus::chooseOptionFromMainMenu();

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
            choice = Menus::chooseOptionFromLoggedUserMenu();

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
