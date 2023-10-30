#ifndef ADDITIONALMETHODS_H
#define ADDITIONALMETHODS_H

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class AdditionalMethods
{
    static int readInteger();

public:
    static char chooseOptionFromMainMenu();
    static char chooseOptionFromLoggedUserMenu();
    static char chooseOptionFromEditMenu();
    static char readSign();
    static string changeFirstLetterCapitalNextSmall(string tekst);
    static string convertIntToString(int liczba);
    static string readLine();
    static string getNumber(string tekst, int pozycjaZnaku);
    static int convertStringToInt(string liczba);

};

#endif
