#include "IncomesFile.h"

int IncomesFile::getLastItemId()
{
    return lastItemId;
}

void IncomesFile::addIncomeToFile(Operation income)
{
    income.setOperationId(lastItemId+1);

    CMarkup xml;

    if (!xml.Load(FILE_NAME))
    {
        xml.AddElem("incomes");
        xml.Save(FILE_NAME);
    }

    xml.Load(FILE_NAME);
    xml.FindElem("incomes");
    xml.IntoElem();

    xml.AddElem("income");
    xml.IntoElem();

    xml.AddElem("incomeId", income.getOperationId());
    xml.AddElem("userId", income.getOperationUserId());
    xml.AddElem("incomeDate", income.getOperationDate());
    xml.AddElem("incomeItem", income.getOperationNameFromUser());
    xml.AddElem("incomeAmount", income.getOperationAmount());

    xml.Save(FILE_NAME);
    ++lastItemId;
}

vector <Operation> IncomesFile::readIncomesFromFile(int idOfLoggedUser)
{
    vector <Operation> incomes;
    Operation income;
    CMarkup xml;

        if (xml.Load(FILE_NAME))
    {
        xml.FindElem("incomes");
        xml.IntoElem();

        while (xml.FindElem("income"))
        {
            xml.IntoElem();
            xml.FindElem("incomeId");
            lastItemId = AdditionalMethods::convertStringToInt(xml.GetElemContent());
            income.setOperationId(lastItemId);
            xml.FindElem("userId");

            if (idOfLoggedUser == AdditionalMethods::convertStringToInt(xml.GetElemContent()))
            {
                income.setOperationuUserId(idOfLoggedUser);
                xml.FindElem("incomeDate");
                income.setOperationDate(AdditionalMethods::convertStringToInt(xml.GetElemContent()));
                xml.FindElem("incomeItem");
                income.setOperationNameFromUser(xml.GetElemContent());
                xml.FindElem("incomeAmount");
                income.setOperationAmount(AdditionalMethods::convertStringToInt(xml.GetElemContent()));
                incomes.push_back(income);
            }

            xml.OutOfElem();        }
    }
    return incomes;
}
