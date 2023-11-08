#ifndef OUTCOMESFILE_H
#define OUTCOMESFILE_H

#include <iostream>
#include <vector>

#include "OperationsFile.h"
#include "OperationType.h"

using namespace std;

class OutcomesFile :public OperationsFile
{
    const IOType ioType = OUTCOME;
public:
    OutcomesFile(string outcomesFileName) : OperationsFile(outcomesFileName){};
};

#endif
