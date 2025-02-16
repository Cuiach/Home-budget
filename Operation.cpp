#include "Operation.h"

void Operation::setOperationId(int newOperationId)
{
    operationId = newOperationId;
}

void Operation::setOperationuUserId(int newOperationUserId)
{
    operationUserId = newOperationUserId;
}

void Operation::setOperationDate(int newOperationDate)
{
    operationDate = newOperationDate;
}

void Operation::setOperationNameFromUser(string newOperationNameFromUser)
{
    operationNameFromUser = newOperationNameFromUser;
}

void Operation::setOperationAmount(float newOperationAmount)
{
    operationAmount = newOperationAmount;
}

int Operation::getOperationId()
{
    return operationId;
}

int Operation::getOperationUserId()
{
    return operationUserId;
}

int Operation::getOperationDate() const
{
    return operationDate;
}

string Operation::getOperationNameFromUser() const
{
    return operationNameFromUser;
}

float Operation::getOperationAmount() const
{
    return operationAmount;
}
