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

string DateMethods::getCurrentYearMonthDayAsStringsWithDashes()
{
    string rawDate = AdditionalMethods::convertIntToString(getCurrentYearMonthDay());
    string dateWithDashes = rawDate.substr(0,4) + "-" + rawDate.substr(4,2) + "-" + rawDate.substr(6,2);
    return dateWithDashes;
}

bool DateMethods::checkDate(string &dateFromUser)
{
    string temporaryLetter = "";
    int year, month , day;
    int currentYear = getCurrentYearMonthDay()/10000;
    int currentMonth = (getCurrentYearMonthDay() - currentYear * 10000) /100;
    int currentDay = (getCurrentYearMonthDay() - currentYear * 10000 - currentMonth * 100);

    if (dateFromUser == "t" || dateFromUser == "T")
    {
        dateFromUser = getCurrentYearMonthDayAsStringsWithDashes();
        return true;
    }

    if (dateFromUser.length() != 10)
    {
        cout << " Niepoprawny format daty. Sprobuj jeszcze raz! \n";
        return false;
    }

    if (!regex_match(dateFromUser, regex("[0-9]{4}-[0-9]{2}-[0-9]{2}")))
    {
        return false;
    }

    try
    {
        year = stoi(dateFromUser.substr(0,4));
        month = stoi(dateFromUser.substr(5,2));
        day = stoi(dateFromUser.substr(8,2));
    }
    catch (const exception &e)
    {
        cout << " Wystapil wyjatek: " << e.what() <<endl;
        return false;
    }

    if (year < 2000 || year > currentYear)
    {
        cout << " Niepoprawny rok. Sprobuj jeszcze raz! \n" << endl;
        return false;
    }

    if (month < 1 || month > 12 || (currentYear == year && month > currentMonth))
    {
        cout << " Niepoprawny miesiac. Sprobuj jeszcze raz! \n" << endl;
        return false;
    }

    if (day < 1 || day > getLastDayOfMonth(year, month) || (currentYear == year && currentMonth == month && day > currentDay))
    {
        cout << " Niepoprawny dzien. Sprobuj jeszcze raz! \n" << endl;
        return false;
    }
    return true;
}

int DateMethods::convertStringDateToInt(string date)
{
    int dateCorrect = stoi(date.substr(0,4) + date.substr(5,2) + date.substr(8,2));
    return dateCorrect;
}
