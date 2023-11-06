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

float AdditionalMethods::convertStringToFloatExcludingZero(string text)
{
    float number = 0;
    int secondPartLength = 0;
    string firstPartOfNumber = getNumber(text, 0);

    if (firstPartOfNumber == text)
        return convertStringToInt(firstPartOfNumber);

    int a = firstPartOfNumber.length();
    if (!(text[a] == ',' || text[a] == '.'))
        return -1;

    string secondPartOfNumber = getNumber(text, firstPartOfNumber.length()+1);

    if (!((firstPartOfNumber.length() + secondPartOfNumber.length() + 1) == text.length()))
        return -1;

    number = convertStringToInt(firstPartOfNumber);
    secondPartLength = secondPartOfNumber.length();
    int secondPart = convertStringToInt(secondPartOfNumber);
    number = number + (secondPart/(pow(10,secondPartLength)));

    if (number == 0)
        return -1;

    return number;
}


int AdditionalMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
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


