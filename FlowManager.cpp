#include "FlowManager.h"

void FlowManager::addOutcome()
{
    cout << " --- Dodajesz wydatek ---\n";
    Operation outcome = getOperationDetails();
    OperationType ioType = OUTCOME;
    outcome.setOperationId(outcomesFile.getLastId() + 1);
    outcomes.push_back(outcome);
    outcomesFile.addOperationToFile(outcome, ioType);
}

void FlowManager::addIncome()
{
    cout << " --- Dodajesz dochod ---\n";
    Operation income = getOperationDetails();
    OperationType ioType = INCOME;
    income.setOperationId(incomesFile.getLastId() + 1);
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

float FlowManager::calculateIncomesOutcomesBalance(int dateFrom, int dateTo, const OperationType & ioType)
{
    vector <Operation> operations = ioType == INCOME ? incomes : outcomes;
    float sum = 0;
    string operationType = ioType == INCOME ? " Przychody" : " Wydatki";

    sort(operations.begin(), operations.end(), [](Operation &firstOperation, Operation &secondOperation)
         { return firstOperation.getOperationDate() < secondOperation.getOperationDate(); } );

    cout << operationType + " z podanego okresu:" << endl;

    operationType = ioType == INCOME ? " Przychod" : " Wydatek";
    for (const Operation &operation : operations)
    {
        if (operation.getOperationDate() >= dateFrom && operation.getOperationDate() <= dateTo)
        {
            cout << operationType << ":" << endl;
            cout << DateMethods::convertIntDatetoStringWithDashes(operation.getOperationDate()) << endl;
            cout << operation.getOperationNameFromUser() << endl;
            cout << operation.getOperationAmount() << endl;
            sum = sum + operation.getOperationAmount();
        }
    }
    return sum;
}

void FlowManager::printIncomesAndOutcomesOfRange(int dateFrom, int dateTo)
{
    float incomesSum = calculateIncomesOutcomesBalance(dateFrom, dateTo, INCOME);
    float outcomesSum = calculateIncomesOutcomesBalance(dateFrom, dateTo, OUTCOME);

    cout << endl << " --------BILANS------- " << endl;
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
    int dateFrom = stoi(DateMethods::getLastMonthFirstAndLastDayDates().substr(0,8));
    int dateTo = stoi(DateMethods::getLastMonthFirstAndLastDayDates().substr(8,8));
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

    } while (DateMethods::convertStringDateToInt(dateFrom) > DateMethods::convertStringDateToInt(dateTo));

    printIncomesAndOutcomesOfRange(DateMethods::convertStringDateToInt(dateFrom), DateMethods::convertStringDateToInt(dateTo));
}
