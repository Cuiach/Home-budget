#ifndef ADDITIONALMETHODS_H
#define ADDITIONALMETHODS_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include "date.h"

using namespace std;

class AdditionalMethods
{
    static int readInteger();

public:
    static char chooseOptionFromMainMenu();
    static char chooseOptionFromLoggedUserMenu();
    static char chooseOptionFromEditMenu();
    static char readSign();
    static int getDateAndConvertToInt();
    static string changeFirstLetterCapitalNextSmall(string text);
    static string convertIntToString(int number);
    static string readLine();
    static int getLastDayOfMonth(int year, int month);
    static int getCurrentYearMonthDay();
    static string getNumber(string text, int signPosition);
    static float convertStringToFloat(string text);
    static int convertStringToInt(string number);
    static int checkAndReturnDate(string dateFromUser);
};

#endif
