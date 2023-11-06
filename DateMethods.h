#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include "date.h"
#include "AdditionalMethods.h"

using namespace std;

class DateMethods
{
public:
    static int getDateAndConvertToInt();
    static int getLastDayOfMonth(int year, int month);
    static int getCurrentYearMonthDay();
    static int checkAndReturnDate(string dateFromUser);
};

#endif
