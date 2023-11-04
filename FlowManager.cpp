#include "FlowManager.h"

void FlowManager::addOutcome()
{
    cout << " --- Dodajesz wydatek ---\n";
    Operation outcome = getOperationDetails();
    outcome.setOperationId(outcomesFile.getLastItemId() + 1);
    outcomes.push_back(outcome);
    outcomesFile.addOutcomeToFile(outcome);
}

void FlowManager::addIncome()
{
    cout << " --- Dodajesz dochod ---\n";
    Operation income = getOperationDetails();
    income.setOperationId(incomesFile.getLastItemId() + 1);
    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);
}

Operation FlowManager::getOperationDetails()
{
    Operation operation;
    int checkFirstOccurence = 0;
    float amountToCheck = 0;

    operation.setOperationuUserId(ID_OF_LOGGED_USER);

    do
    {
        if (checkFirstOccurence != 0)
        {
            cout << "Blednie podana kwota. Sprobuj jeszcze raz!";
        }
        cout << " Kwota: ";
        amountToCheck = AdditionalMethods::convertStringToFloat(AdditionalMethods::readLine());
        ++checkFirstOccurence;
    } while (amountToCheck == -1);

    operation.setOperationAmount(amountToCheck);

    operation.setOperationDate(AdditionalMethods::getDateAndConvertToInt());

    cout << " Rodzaj/nazwa/typ: ";
    operation.setOperationNameFromUser(AdditionalMethods::readLine());

    return operation;
}

void FlowManager::printIncomesAndOutcomesOfRange(int dateFrom, int dateTo)
{
    Operation temporaryOperation;
    int dateSearched;
    float incomesSum = 0;
    float outcomesSum = 0;

    for (size_t i = 0; i < incomes.size(); i++)
    {
        temporaryOperation = incomes[i];
        dateSearched = temporaryOperation.getOperationDate();
        if (dateSearched >= dateFrom && dateSearched <= dateTo)
        {
            incomesSum = incomesSum + temporaryOperation.getOperationAmount();
            cout << endl << temporaryOperation.getOperationDate();
            cout << endl << temporaryOperation.getOperationAmount();
            cout << endl << temporaryOperation.getOperationNameFromUser() << endl;
        }
    }
    cout << " Suma przychodow: " << incomesSum << endl;
    system("pause");

    for (size_t i = 0; i < outcomes.size(); i++)
    {
        temporaryOperation = outcomes[i];
        dateSearched = temporaryOperation.getOperationDate();
        if (dateSearched >= dateFrom && dateSearched <= dateTo)
            {
                outcomesSum = outcomesSum + temporaryOperation.getOperationAmount();
                cout << endl << temporaryOperation.getOperationDate();
                cout << endl << temporaryOperation.getOperationAmount();
                cout << endl << temporaryOperation.getOperationNameFromUser() << endl;
            }
    }
    cout << " Suma wydatkow: " << outcomesSum << endl;
    cout << " Bilans: " << incomesSum - outcomesSum << endl;
    system("pause");
}

void FlowManager::printIO()
{
        for (size_t i = 0; i < incomes.size(); i++)
    {
        cout << endl << incomes[i].getOperationId();
        cout << endl << incomes[i].getOperationDate();
        cout << endl << incomes[i].getOperationAmount();
        cout << endl << incomes[i].getOperationNameFromUser() << endl;
    }
    system("pause");

        for (size_t i = 0; i < outcomes.size(); i++)
    {
        cout << endl << outcomes[i].getOperationId();
        cout << endl << outcomes[i].getOperationDate();
        cout << endl << outcomes[i].getOperationAmount();
        cout << endl << outcomes[i].getOperationNameFromUser() << endl;
    }
    system("pause");
}

