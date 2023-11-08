#include "DateMethods.h"

int DateMethods::getLastDayOfMonth(int year, int month)
{
    int lastDayOfMonth = 0;

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        lastDayOfMonth = 31;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11))
    {
        lastDayOfMonth = 30;
    }
    else if ((month == 2) && (year % 4 == 0))
    {
        lastDayOfMonth = 29;
    }
    else if ((month == 2) && (year % 4 != 0))
    {
        lastDayOfMonth = 28;
    }

    return lastDayOfMonth;
}

int DateMethods::getCurrentYearMonthDay()
{
    time_t temporaryTime = time(nullptr);
    tm *const timeToGetYearMonthDay = localtime(&temporaryTime);
    int year = 1900 + timeToGetYearMonthDay->tm_year;
    int month = timeToGetYearMonthDay->tm_mon + 1;
    int day = timeToGetYearMonthDay->tm_mday;
    return year*10000 + month*100 + day;
}

int DateMethods::checkAndReturnDate(string dateFromUser)
{
    string temporaryLetter = "";
    int year, month , day;
    int currentYear = getCurrentYearMonthDay()/10000;
    int currentMonth = (getCurrentYearMonthDay() - currentYear * 10000) /100;
    int currentDay = (getCurrentYearMonthDay() - currentYear * 10000 - currentMonth * 100);
    system("pause");

    if (dateFromUser.length() != 10) return 0;

    year = AdditionalMethods::convertStringToInt(AdditionalMethods::getNumber(dateFromUser, 0));
    if (year < 2000 || year > currentYear) return 0;

    month = AdditionalMethods::convertStringToInt(AdditionalMethods::getNumber(dateFromUser, 5));
    if ((currentYear == year && (month < 1 || month > currentMonth)) || (currentYear != year && (month < 1 || month > 12))) return 0;

    day = AdditionalMethods::convertStringToInt(AdditionalMethods::getNumber(dateFromUser,8));
    if (((currentYear == year && currentMonth == month) && (day < 1 || day > currentDay))
    ||  ((!(currentYear == year && currentMonth == month)) && (day < 1 || day > getLastDayOfMonth(year, month)))) return 0;

    temporaryLetter = dateFromUser[4];
    if (temporaryLetter != "-") return 0;

    temporaryLetter = dateFromUser[7];
    if (temporaryLetter != "-") return 0;

    return 10000*year + 100*month + day;
}

int DateMethods::getDateAndConvertToInt()
{
    int dateFromUser = 0;
    string checkIfDash1 = "";
    string checkIfDash2 = "";
    int checkFisrtOccurence = 0;

    while (dateFromUser == 0)
    {
        if (checkFisrtOccurence != 0)
        {
            cout << " Blednie podana data. Sprobuj jeszcze raz! \n";
        }
        cout << " Wprowadz date w formacie rrrr-mm-dd: ";
        dateFromUser = checkAndReturnDate(AdditionalMethods::readLine());
        ++checkFisrtOccurence;
    }
    return dateFromUser;
}
