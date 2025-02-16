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
    float operationAmount;

public:
    void setOperationId(int newOperationId);
    void setOperationuUserId(int newOperationUserId);
    void setOperationDate(int newOperationDate);
    void setOperationNameFromUser(string newOperationNameFromUser);
    void setOperationAmount(float newOperationAmount);

    int getOperationId();
    int getOperationUserId();
    int getOperationDate() const;
    string getOperationNameFromUser() const;
    float getOperationAmount() const;
};

#endif
