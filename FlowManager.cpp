#include "FlowManager.h"

void FlowManager::addOutcome()
{
    cout << " --- Dodajesz wydatek ---\n";
    Operation outcome = getOperationDetails();
    outcomes.push_back(outcome);
    outcomesFile.addOutcomeToFile(outcome);
}

void FlowManager::addIncome()
{
    cout << " --- Dodajesz dochod ---\n";
    Operation income = getOperationDetails();
    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);
}

Operation FlowManager::getOperationDetails()
{
    Operation operation;

    operation.setOperationId(0);
//Pytanie: To powyzsze - zerowac operationId czy zostawic, jak jest, a i tak wartosc zostanie zmieniona w incomeFile.addIncome ?

    operation.setOperationuUserId(ID_OF_LOGGED_USER);

    cout << " Kwota: " << endl;
    operation.setOperationAmount(AdditionalMethods::convertStringToInt(AdditionalMethods::readLine()));

    cout << " Data: " << endl;
    operation.setOperationDate(AdditionalMethods::getDateAndConvertToInt());

    cout << " Rodzaj/nazwa/typ: " << endl;
    operation.setOperationNameFromUser(AdditionalMethods::readLine());

    return operation;
}

void FlowManager::printAllIncomesAndOutcomes()
{
    for (size_t i = 0; i < incomes.size(); i++)
    {
        cout << endl << incomes[i].getOperationAmount();
        cout << endl << incomes[i].getOperationNameFromUser() << endl;
    }
    system("pause");
        for (size_t i = 0; i < outcomes.size(); i++)
    {
        cout << endl << outcomes[i].getOperationAmount();
        cout << endl << outcomes[i].getOperationNameFromUser() << endl;
    }
    system("pause");
}

