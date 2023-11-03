#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Markup.h"
#include "User.h"
#include "AdditionalMethods.h"
#include "DataFile.h"

using namespace std;

class UsersFile :public DataFile::DataFile
{
public:
    UsersFile(string fileName) : DataFile(fileName) {};
    vector <User> readUsersFromFile();
    void addUserToFile(User user);
    void writeAllUsersInFile(vector <User> &users);
};

#endif
