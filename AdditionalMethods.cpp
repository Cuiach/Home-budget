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
    cout << "3. Wyswietl przychody i dochody (kiedys bedzie->Bilans z biezacego miesiaca)" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
//    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = readSign();


    return choice;
}

char AdditionalMethods::chooseOptionFromEditMenu()
{
    char choice;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
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

int AdditionalMethods::getDateAndConvertToInt()
{
    int year, month, day;

    cout << " Rok: ";
    year = readInteger();
    while (year < 2000 || year > 2023)
    {
        cout << " Bledny rok. Wpisz jeszcze raz wlasciwy rok: ";
        year = readInteger();
    }

    cout << " Miesiac: ";
    month = readInteger();
    while (month < 1 || month > 12)
    {
        cout << " Bledny miesiac. \n Rok: " + convertIntToString(year) + " \n Wpisz jeszcze raz wlasciwy miesiac: ";
        month = readInteger();
    }

    cout << " Dzien: ";
    day = readInteger();
    string dataTaka = convertIntToString(year) + "-" + convertIntToString(month) + "-" + convertIntToString(day);
    cout << dataTaka;
    cout << "AAA";
    while (!(
                ((month == 1 || month == 3 || month == 5 || month == 7 ||
                month == 8 || month == 10 || month == 12) && (day<=31 && day>=1))
             ||
                ((month == 4 || month == 6 || month == 9 || month == 11) && (day<=30 && day>=1))
             ||
                ((month == 2) && (year % 4 == 0) && (day<=29 && day>=1))
             ||
                ((month == 2) && (year % 4 != 0) && (day<=28 && day>=1))
             ))
    {
        cout << " Rok: " + convertIntToString(year) + " \n Miesiac: " + convertIntToString(month) + "\n Bledny dzien. Wpisz jeszcze raz wlasciwy dzien: ";
        day = readInteger();
    }
    return (year*10000 + month*100 + day);
}

string AdditionalMethods::changeFirstLetterCapitalNextSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

bool AdditionalMethods::isDateOneEarlierThanDateTwo(int date1, int date2)
{
    int year1 = convertStringToInt(convertIntToString(date1).substr(0,4));
    int year2 = convertStringToInt(convertIntToString(date2).substr(0,4));
    if (year1 < year2)
        return true;
    else if (year1 > year2)
        return false;

    int month1 = convertStringToInt(convertIntToString(date1).substr(4,2));
    int month2 = convertStringToInt(convertIntToString(date2).substr(4,2));
    if (month1 < month2)
        return true;
    else if (month1 > month2)
        return false;

    int day1 = convertStringToInt(convertIntToString(date1).substr(6,2));
    int day2 = convertStringToInt(convertIntToString(date2).substr(6,2));
    if (day1 < day2)
        return true;
//    else if (day1 > day2)
    return false;
}

