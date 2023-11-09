#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>
#include "date.h"
#include "AdditionalMethods.h"

using namespace std;

class DateMethods
{
    static string getCurrentYearMonthDayAsStringsWithDashes();
public:
    static int getLastDayOfMonth(int year, int month);
    static int getCurrentYearMonthDay();
    static bool checkDate(string &dateFromUser);
    static int convertStringDateToInt(string date);
};

#endif
