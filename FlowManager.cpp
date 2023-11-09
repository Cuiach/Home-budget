#include "FlowManager.h"

void FlowManager::addOutcome()
{
    cout << " --- Dodajesz wydatek ---\n";
    Operation outcome = getOperationDetails();
    IOType ioType = OUTCOME;
    outcome.setOperationId(outcomesFile.getLastItemId() + 1);
    outcomes.push_back(outcome);
    outcomesFile.addOperationToFile(outcome, ioType);
}

void FlowManager::addIncome()
{
    cout << " --- Dodajesz dochod ---\n";
    Operation income = getOperationDetails();
    IOType ioType = INCOME;
    income.setOperationId(incomesFile.getLastItemId() + 1);
    incomes.push_back(income);
    incomesFile.addOperationToFile(income, ioType);
}

Operation FlowManager::getOperationDetails()
{
    Operation operation;
    int checkFirstOccurence = 0;
    float amountToCheck = 0;
    string dateFromUser = "";

    operation.setOperationuUserId(ID_OF_LOGGED_USER);

    do
    {
        if (checkFirstOccurence != 0)
        {
            cout << "Blednie podana kwota. Sprobuj jeszcze raz!";
        }
        cout << " Kwota: ";
        amountToCheck = AdditionalMethods::convertStringToFloatExcludingZero(AdditionalMethods::readLine());
        ++checkFirstOccurence;
    } while (amountToCheck == -1);

    operation.setOperationAmount(amountToCheck);

    do
    {
        cout << " Wprowadz date w formacie rrrr-mm-dd. Wprowadz t, jesli chcesz wpisac dzisiejsza date: ";
        dateFromUser = AdditionalMethods::readLine();
    } while (!DateMethods::checkDate(dateFromUser));

    operation.setOperationDate(DateMethods::convertStringDateToInt(dateFromUser));

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
            cout << endl << temporaryOperation.getOperationId();
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
                cout << endl << temporaryOperation.getOperationId();
                cout << endl << temporaryOperation.getOperationDate();
                cout << endl << temporaryOperation.getOperationAmount();
                cout << endl << temporaryOperation.getOperationNameFromUser() << endl;
            }
    }
    cout << " Suma wydatkow: " << outcomesSum << endl << endl;
    cout << " --------BILANS------- " << endl;
    cout << " Przychody: " << incomesSum << endl;
    cout << " Wydatki: " << outcomesSum << endl;
    cout << " Bilans: " << incomesSum - outcomesSum << endl;
    system("pause");
}

void FlowManager::printThisMonthInOut()
{
    int dateFrom = 0;
    int dateTo = 0;
    int year = DateMethods::getCurrentYearMonthDay()/10000;
    int month = (DateMethods::getCurrentYearMonthDay() - year*10000) / 100;

    dateFrom = year*10000 + (month)*100 + 1;
    dateTo = year*10000 + (month)*100 + DateMethods::getLastDayOfMonth(year, month);

    printIncomesAndOutcomesOfRange(dateFrom, dateTo);
}

void FlowManager::printLastMonthInOut()
{
    int dateFrom = 0;
    int dateTo = 0;
    int year = DateMethods::getCurrentYearMonthDay() / 10000;
    int month = (DateMethods::getCurrentYearMonthDay() - year * 10000) / 100;

    if (month != 1)
    {
        month = month -1;
        dateFrom = year*10000 + (month)*100 + 1;
        dateTo = year*10000 + (month)*100 + DateMethods::getLastDayOfMonth(year, month);
    }
    else
    {
      dateFrom = (year-1)*10000 + 1201;
      dateFrom = (year-1)*10000 + 1231;
    }

    printIncomesAndOutcomesOfRange(dateFrom, dateTo);
}

void FlowManager::printChosenRangeInOut()
{
    string dateFrom = "";
    string dateTo = "";
    int excludeFirstOccurence = 0;

    do {
        if (excludeFirstOccurence != 0)
        {
            cout << endl << " Data konca musi byc po dacie poczatku. Sprobuj jeszcze raz";
        }

        do {
            cout << endl << " Wpisz date poczatku obliczenia bilansu: ";
            dateFrom = AdditionalMethods::readLine();
        } while (!DateMethods::checkDate(dateFrom));

        do {
            cout << endl << " Wpisz date konca obliczenia bilansu: ";
            dateTo = AdditionalMethods::readLine();
        } while (!DateMethods::checkDate(dateTo));

        ++excludeFirstOccurence;

    } while (stoi(dateFrom) > stoi(dateTo));

    printIncomesAndOutcomesOfRange(stoi(dateFrom), stoi(dateTo));
}
