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

    operation.setOperationuUserId(ID_OF_LOGGED_USER);

    cout << " Kwota: " << endl;
    operation.setOperationAmount(AdditionalMethods::convertStringToInt(AdditionalMethods::readLine()));

    cout << " Data: " << endl;
    operation.setOperationDate(AdditionalMethods::getDateAndConvertToInt());

    cout << " Rodzaj/nazwa/typ: " << endl;
    operation.setOperationNameFromUser(AdditionalMethods::readLine());

    return operation;
}

void FlowManager::printIncomesAndOutcomesOfRange(int dateFrom, int dateTo)
{
    vector <Operation> incomesOfRange;
    vector <Operation> outcomesOfRange;
    Operation temporaryOperation;
    int dateSearched;
    int incomesSum = 0;
    int outcomesSum = 0;

    for (size_t i = 0; i < incomes.size(); i++)
    {
        temporaryOperation = incomes[i];
        dateSearched = temporaryOperation.getOperationDate();
        if (AdditionalMethods::isDateOneEarlierThanDateTwo(dateFrom, dateSearched) && AdditionalMethods::isDateOneEarlierThanDateTwo(dateSearched, dateTo))
            {
                incomesOfRange.push_back(temporaryOperation);
            }
    }

    for (size_t i = 0; i < outcomes.size(); i++)
    {
        temporaryOperation = outcomes[i];
        dateSearched = temporaryOperation.getOperationDate();
        if (AdditionalMethods::isDateOneEarlierThanDateTwo(dateFrom, dateSearched) && AdditionalMethods::isDateOneEarlierThanDateTwo(dateSearched, dateTo))
            {
                outcomesOfRange.push_back(temporaryOperation);
            }
    }

    for (size_t i = 0; i < incomesOfRange.size(); i++)
    {
        incomesSum = incomesSum + incomesOfRange[i].getOperationAmount();
        cout << endl << incomesOfRange[i].getOperationId();
        cout << endl << incomesOfRange[i].getOperationAmount();
        cout << endl << incomesOfRange[i].getOperationNameFromUser() << endl;
    }

    cout << " Suma przychodow: " << incomesSum << endl;
    system("pause");

        for (size_t i = 0; i < outcomesOfRange.size(); i++)
    {
        outcomesSum = outcomesSum + outcomesOfRange[i].getOperationAmount();
        cout << endl << outcomesOfRange[i].getOperationId();
        cout << endl << outcomesOfRange[i].getOperationDate();
        cout << endl << outcomesOfRange[i].getOperationAmount();
        cout << endl << outcomesOfRange[i].getOperationNameFromUser() << endl;
    }

    cout << " Suma wydatkow: " << outcomesSum << endl;
    cout << " Bilans: " << incomesSum - outcomesSum << endl;
    system("pause");
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

