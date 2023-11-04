#include "AdditionalMethods.h"

char AdditionalMethods::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = readSign();

    return choice;
}

char AdditionalMethods::chooseOptionFromLoggedUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "8. wszystkie in & out" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = readSign();


    return choice;
}

char AdditionalMethods::readSign()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

int AdditionalMethods::readInteger()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}


string AdditionalMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AdditionalMethods::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

int AdditionalMethods::getLastDayOfMonth(int year, int month)
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

int AdditionalMethods::getCurrentYearMonthDay()
{
    time_t temporaryTime = time(nullptr);
    tm *const timeToGetYearMonthDay = localtime(&temporaryTime);
    int year = 1900 + timeToGetYearMonthDay->tm_year;
    int month = timeToGetYearMonthDay->tm_mon + 1;
    int day = timeToGetYearMonthDay->tm_mday + 1;
    return year*10000 + month*100 + day;
}

string AdditionalMethods::getNumber(string text, int signPosition)
{
    string number = "";
    while(isdigit(text[signPosition]))
    {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}

int AdditionalMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

int AdditionalMethods::checkAndReturnDate(string dateFromUser)
{
    string temporaryLetter = "";
    int year, month , day;
    int currentYear = convertStringToInt(convertIntToString(getCurrentYearMonthDay()).substr(0,4));
    int currentMonth = convertStringToInt(convertIntToString(getCurrentYearMonthDay()).substr(4,2));
    int currentDay = convertStringToInt(convertIntToString(getCurrentYearMonthDay()).substr(6,2));

    if (dateFromUser.length() != 10) return 0;

    year = convertStringToInt(getNumber(dateFromUser, 0));
    if (year < 2000 || year > currentYear) return 0;

    month = convertStringToInt(getNumber(dateFromUser, 5));
    if ((currentYear == year && (month < 1 || month > currentMonth)) || (currentYear != year && (month < 1 || month > 12))) return 0;

    day = convertStringToInt(getNumber(dateFromUser,8));
    if (((currentYear == year && currentMonth == month) && (day < 1 || day > currentDay)) ||  (currentYear == year && currentMonth == month) && (day < 1 || day > getLastDayOfMonth(year, month))) return 0;

    temporaryLetter = dateFromUser[4];
    if (temporaryLetter != "-") return 0;

    temporaryLetter = dateFromUser[7];
    if (temporaryLetter != "-") return 0;

    return 10000*year + 100*month + day;
}

int AdditionalMethods::getDateAndConvertToInt()
{
    int dateFromUser = 0;
    string checkIfDash1 = "";
    string checkIfDash2 = "";
    int year, month, day;
    int checkFisrtOccurence = 0;

    while (dateFromUser == 0)
    {
        if (checkFisrtOccurence != 0)
        {
            cout << " Blednie podana data. Sprobuj jeszcze raz! \n";
        }
        cout << " Wprowadz date w formacie rrrr-mm-dd: ";
        dateFromUser = checkAndReturnDate(readLine());
        ++checkFisrtOccurence;
    }
    return dateFromUser;
}

//int AdditionalMethods::getDateAndConvertToInt()
//{
//    int year, month, day;
//
//    cout << " Rok: ";
//    year = readInteger();
//    while (year < 2000 || year > 2023)
//    {
//        cout << " Bledny rok. Wpisz jeszcze raz wlasciwy rok: ";
//        year = readInteger();
//    }
//
//    cout << " Miesiac: ";
//    month = readInteger();
//    while (month < 1 || month > 12)
//    {
//        cout << " Bledny miesiac. \n Rok: " + convertIntToString(year) + " \n Wpisz jeszcze raz wlasciwy miesiac: ";
//        month = readInteger();
//    }
//
//    cout << " Dzien: ";
//    day = readInteger();
//
//    while (!(
//                ((month == 1 || month == 3 || month == 5 || month == 7 ||
//                month == 8 || month == 10 || month == 12) && (day<=31 && day>=1))
//             ||
//                ((month == 4 || month == 6 || month == 9 || month == 11) && (day<=30 && day>=1))
//             ||
//                ((month == 2) && (year % 4 == 0) && (day<=29 && day>=1))
//             ||
//                ((month == 2) && (year % 4 != 0) && (day<=28 && day>=1))
//             ))
//    {
//        cout << " Rok: " + convertIntToString(year) + " \n Miesiac: " + convertIntToString(month) + "\n Bledny dzien. Wpisz jeszcze raz wlasciwy dzien: ";
//        day = readInteger();
//    }
//    return (year*10000 + month*100 + day);
//}

string AdditionalMethods::changeFirstLetterCapitalNextSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}


