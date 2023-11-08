#include "OperationsFile.h"

#include "IncomesFile.h"

//int OperationsFile::getLastItemId()
//{
//    return lastItemId;
//}

string getOperationTypeName(IOType ioType)
{
    string typeNameSingular;
    switch (ioType){
    case INCOME:
        typeNameSingular = "income";
        break;
    case OUTCOME:
        typeNameSingular = "outcome";
        break;
    }
    return typeNameSingular;
}

void OperationsFile::addOperationToFile(Operation operation, IOType ioType)
{
/*usunac*/ cout << "Wypisuje, jak nalezy?: " + getOperationTypeName(ioType)+"s" + " " + FILE_NAME; system("pause");
    operation.setOperationId(lastItemId+1);

    CMarkup xml;

    if (!xml.Load(FILE_NAME))
    {
cout << "CZYLI NIE PRZECHODZI "; system("pause");
        xml.AddElem(getOperationTypeName(ioType)+"s");
        xml.Save(FILE_NAME);
    }


if (xml.Load(FILE_NAME)) {cout << "W ADD PRZECHODZI "; system("pause");}
//    xml.Load(FILE_NAME);
    xml.FindElem(getOperationTypeName(ioType)+"s");
    xml.IntoElem();

    xml.AddElem(getOperationTypeName(ioType));
    xml.IntoElem();

    xml.AddElem(getOperationTypeName(ioType)+"Id", operation.getOperationId());
    xml.AddElem("userId", operation.getOperationUserId());
    xml.AddElem(getOperationTypeName(ioType)+"Date", operation.getOperationDate());
    xml.AddElem(getOperationTypeName(ioType)+"Item", operation.getOperationNameFromUser());
    xml.AddElem(getOperationTypeName(ioType)+"Amount", to_string(operation.getOperationAmount()));

    xml.Save(FILE_NAME);
    ++lastItemId;
}

vector <Operation> OperationsFile::readOperationsFromFile(int idOfLoggedUser, IOType ioType)
{
    vector <Operation> operations;
    Operation operation;
    CMarkup xml;

cout << FILE_NAME;
system("pause");

        if (xml.Load(FILE_NAME))
    {
cout << "PRZESZLO! ";
system("pause");

        xml.FindElem(getOperationTypeName(ioType)+"s");
        xml.IntoElem();

        while (xml.FindElem(getOperationTypeName(ioType)))
        {
            xml.IntoElem();
            xml.FindElem(getOperationTypeName(ioType)+"Id");
            lastItemId = AdditionalMethods::convertStringToInt(xml.GetElemContent());
            operation.setOperationId(lastItemId);
            xml.FindElem("userId");

            if (idOfLoggedUser == AdditionalMethods::convertStringToInt(xml.GetElemContent()))
            {
                operation.setOperationuUserId(idOfLoggedUser);
                xml.FindElem(getOperationTypeName(ioType)+"Date");
                operation.setOperationDate(AdditionalMethods::convertStringToInt(xml.GetElemContent()));
                xml.FindElem(getOperationTypeName(ioType)+"Item");
                operation.setOperationNameFromUser(xml.GetElemContent());
                xml.FindElem(getOperationTypeName(ioType)+"Amount");
                operation.setOperationAmount(AdditionalMethods::convertStringToFloatExcludingZero(xml.GetElemContent()));
                operations.push_back(operation);
            }

            xml.OutOfElem();        }
    }
    return operations;
}

