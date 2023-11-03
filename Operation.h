#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;

class Operation
{
    int operationId;
    int operationUserId;
    int operationDate;
    string operationNameFromUser;
    int operationAmount;

public:
    void setOperationId(int newOperationId);
    void setOperationuUserId(int newOperationUserId);
    void setOperationDate(int newOperationDate);
    void setOperationNameFromUser(string newOperationNameFromUser);
    void setOperationAmount(int newOperationAmount);

    int getOperationId();
    int getOperationUserId();
    int getOperationDate();
    string getOperationNameFromUser();
    int getOperationAmount();
};

#endif
