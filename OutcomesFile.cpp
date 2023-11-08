#include "OutcomesFile.h"

int OutcomesFile::getLastItemId()
{
    return lastItemId;
}

void OutcomesFile::addOutcomeToFile(Operation outcome)
{
    outcome.setOperationId(lastItemId+1);

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
    xml.AddElem("outcomeAmount", to_string(outcome.getOperationAmount()));

    xml.Save("Outcomes.xml");
    ++lastItemId;
}

//vector <Operation> OutcomesFile::readOutcomesFromFile(int idOfLoggedUser)
//{
//    vector <Operation> outcomes;
//    Operation outcome;
//    CMarkup xml;
//
//        if (xml.Load("Outcomes.xml"))
//    {
//        xml.FindElem("outcomes");
//        xml.IntoElem();
//
//        while (xml.FindElem("outcome"))
//        {
//            xml.IntoElem();
//            xml.FindElem("outcomeId");
//            lastItemId = AdditionalMethods::convertStringToInt(xml.GetElemContent());
//            outcome.setOperationId(lastItemId);
//            xml.FindElem("userId");
//
//            if (idOfLoggedUser == AdditionalMethods::convertStringToInt(xml.GetElemContent()))
//            {
//                outcome.setOperationuUserId(idOfLoggedUser);
//                xml.FindElem("outcomeDate");
//                outcome.setOperationDate(AdditionalMethods::convertStringToInt(xml.GetElemContent()));
//                xml.FindElem("outcomeItem");
//                outcome.setOperationNameFromUser(xml.GetElemContent());
//                xml.FindElem("outcomeAmount");
//                outcome.setOperationAmount(AdditionalMethods::convertStringToFloatExcludingZero(xml.GetElemContent()));
//                outcomes.push_back(outcome);
//            }
//
//            xml.OutOfElem();
//        }
//    }
//    return outcomes;
//}
