#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string login;
    string password;
    string name;
    string lastName;

public:
    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setLastName(string newLastName);

    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getLastName();
};

#endif
