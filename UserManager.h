#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UsersFile.h"
#include "AdditionalMethods.h"

using namespace std;

class UserManager
{
    int idOfLoggedUser;
    vector <User> users;

    int getIdOfNewUser();
    bool loginExists(string login);
    User putNewUserDetails();

    UsersFile usersFile;

public:
    UserManager(string nameOfUsersFile) : usersFile(nameOfUsersFile){
        idOfLoggedUser = 0;
        users = usersFile.readUsersFromFile();
    };

    int getIdOfLoggedUser();
    bool isUserLoggedIn();
    void registerUser();
    int logUserIn();
    void changePasswordOfLoggedUser();
    void logUserOut();
};

#endif
