#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>

#include "OperationsFile.h"
#include "OperationType.h"

using namespace std;

class IncomesFile :public OperationsFile
{
    const IOType ioType = INCOME;
public:
    IncomesFile(string incomesFileName) : OperationsFile(incomesFileName){};
};

#endif
