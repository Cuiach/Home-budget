#include "OutcomesFile.h"

int OutcomesFile::getLastItemId()
{
    return lastOutcomeId;
}

void OutcomesFile::addOutcomeToFile(Operation outcome)
{
    outcome.setOperationId(lastOutcomeId+1);

    CMarkup xml;

    if (!xml.Load("Outcomes.xml"))
    {
        xml.AddElem("outcomes");
        xml.Save("Outcomes.xml");
    }

    xml.Load("Outcomes.xml");
    xml.FindElem("outcomes");
    xml.IntoElem();

    xml.AddElem("outcome");
    xml.IntoElem();

    xml.AddElem("outcomeId", outcome.getOperationId());
    xml.AddElem("userId", outcome.getOperationUserId());
    xml.AddElem("outcomeDate", outcome.getOperationDate());
    xml.AddElem("outcomeItem", outcome.getOperationNameFromUser());
    xml.AddElem("outcomeAmount", outcome.getOperationAmount());

    xml.Save("Outcomes.xml");
    ++lastOutcomeId;
}

vector <Operation> OutcomesFile::readOutcomesFromFile(int idOfLoggedUser)
{
    vector <Operation> outcomes;
    Operation outcome;
    CMarkup xml;

        if (xml.Load("Outcomes.xml"))
    {
        xml.FindElem("outcomes");
        xml.IntoElem();

        while (xml.FindElem("outcome"))
        {
            xml.IntoElem();
            xml.FindElem("outcomeId");
            lastOutcomeId = AdditionalMethods::convertStringToInt(xml.GetElemContent());
/*usunac*/            cout << lastOutcomeId << endl;
            system("pause");
            outcome.setOperationId(lastOutcomeId);
            xml.FindElem("userId");

            if (idOfLoggedUser == AdditionalMethods::convertStringToInt(xml.GetElemContent()))
            {
                outcome.setOperationuUserId(idOfLoggedUser);
                xml.FindElem("outcomeDate");
                outcome.setOperationDate(AdditionalMethods::convertStringToInt(xml.GetElemContent()));
                xml.FindElem("outcomeItem");
                outcome.setOperationNameFromUser(xml.GetElemContent());
                xml.FindElem("outcomeAmount");
                outcome.setOperationAmount(AdditionalMethods::convertStringToInt(xml.GetElemContent()));
                outcomes.push_back(outcome);
            }

            xml.OutOfElem();
        }
    }
    return outcomes;
}
