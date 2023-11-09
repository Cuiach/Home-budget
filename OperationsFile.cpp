#include "OperationsFile.h"

int OperationsFile::getLastItemId(){
    return lastItemId;}

string OperationsFile::getOperationTypeName(IOType ioType)
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
    operation.setOperationId(lastItemId+1);

    CMarkup xml;

    if (!xml.Load(getFileName()))
    {
        xml.AddElem(getOperationTypeName(ioType)+"s");
        xml.Save(getFileName());
    }

    xml.Load(getFileName());
    xml.FindElem(getOperationTypeName(ioType)+"s");
    xml.IntoElem();

    xml.AddElem(getOperationTypeName(ioType));
    xml.IntoElem();

    xml.AddElem(getOperationTypeName(ioType)+"Id", operation.getOperationId());
    xml.AddElem("userId", operation.getOperationUserId());
    xml.AddElem(getOperationTypeName(ioType)+"Date", operation.getOperationDate());
    xml.AddElem(getOperationTypeName(ioType)+"Item", operation.getOperationNameFromUser());
    xml.AddElem(getOperationTypeName(ioType)+"Amount", to_string(operation.getOperationAmount()));

    xml.Save(getFileName());
    ++lastItemId;
}

vector <Operation> OperationsFile::readOperationsFromFile(int idOfLoggedUser, IOType ioType)
{
    vector <Operation> operations;
    Operation operation;
    CMarkup xml;

    if (xml.Load(getFileName()))
    {
        xml.FindElem(getOperationTypeName(ioType)+"s");
        xml.IntoElem();

        while (xml.FindElem(getOperationTypeName(ioType)))
        {
            xml.IntoElem();
            xml.FindElem(getOperationTypeName(ioType)+"Id");
            lastItemId = stoi(xml.GetElemContent());
            operation.setOperationId(lastItemId);
            xml.FindElem("userId");

            if (idOfLoggedUser == stoi(xml.GetElemContent()))
            {
                operation.setOperationuUserId(idOfLoggedUser);
                xml.FindElem(getOperationTypeName(ioType)+"Date");
                operation.setOperationDate(stoi(xml.GetElemContent()));
                xml.FindElem(getOperationTypeName(ioType)+"Item");
                operation.setOperationNameFromUser(xml.GetElemContent());
                xml.FindElem(getOperationTypeName(ioType)+"Amount");
                operation.setOperationAmount(AdditionalMethods::convertStringToFloatExcludingZero(xml.GetElemContent()));
                operations.push_back(operation);
            }
            xml.OutOfElem();
        }
    }
    return operations;
}
