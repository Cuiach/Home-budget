#include "AdditionalMethods.h"

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
    cin.sync();
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
    int placeForCommaOrDot;
    string firstPartOfNumber = getNumber(text, 0);

    if (firstPartOfNumber == text)
    {
        return stoi(firstPartOfNumber);
    }

    placeForCommaOrDot = firstPartOfNumber.length();

    if (!(text[placeForCommaOrDot] == ',' || text[placeForCommaOrDot] == '.'))
    {
        return -1;
    }

    string secondPartOfNumber = getNumber(text, firstPartOfNumber.length()+1);

    if (!((firstPartOfNumber.length() + secondPartOfNumber.length() + 1) == text.length()))
    {
        return -1;
    }

    number = stoi(firstPartOfNumber);
    secondPartLength = secondPartOfNumber.length();
    int secondPart = stoi(secondPartOfNumber);
    number = number + (secondPart/(pow(10,secondPartLength)));

    if (number == 0)
    {
        return -1;
    }

    return number;
}

//string AdditionalMethods::changeFirstLetterCapitalNextSmall(string text)
//{
//    if (!text.empty())
//    {
//        transform(text.begin(), text.end(), text.begin(), ::tolower);
//        text[0] = toupper(text[0]);
//    }
//    return text;
//}
//
//
