#include "UsersFile.h"

void UsersFile::writeAllUsersInFile(vector <User> &users)
{
    fstream dataFile;
    string lineWithUserDetails = "";

    CMarkup xml;

    remove("Users.xml");
    xml.Load("Users.xml");
    xml.AddElem("Users");
    xml.Save( "Users.xml" );

    xml.Load("Users.xml");
    xml.FindElem("Users");
    xml.IntoElem();

    for (User oneUser : users)
    {
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("ID", AdditionalMethods::convertIntToString(oneUser.getId()));
        xml.AddElem("login", oneUser.getLogin());
        xml.AddElem("password", oneUser.getPassword());
        xml.AddElem("name", oneUser.getName());
        xml.AddElem("lastName", oneUser.getLastName());
        xml.OutOfElem();
    }
    xml.Save("Users.xml");
}

vector <User> UsersFile::readUsersFromFile()
{
    User user;
    vector <User> users;

    CMarkup xml;

    if (xml.Load("Users.xml"))
    {
        xml.FindElem("Users");
        xml.IntoElem();

        while (xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("ID");
            user.setId(stoi(xml.GetElemContent()));
            xml.FindElem("login");
            user.setLogin(xml.GetElemContent());
            xml.FindElem("password");
            user.setPassword(xml.GetElemContent());
            xml.FindElem("name");
            user.setName(xml.GetElemContent());
            xml.FindElem("lastName");
            user.setLastName(xml.GetElemContent());
            xml.OutOfElem();
            users.push_back(user);
        }
    }
    return users;
}

void UsersFile::addUserToFile(User user)
{
    CMarkup xml;

    if (!xml.Load("Users.xml"))
    {
        xml.AddElem( "Users" );
        xml.Save( "Users.xml" );
    }

    xml.Load("Users.xml");
    xml.FindElem("Users");
    xml.IntoElem();

    xml.AddElem("User");
    xml.IntoElem();

    xml.AddElem("ID", AdditionalMethods::convertIntToString(user.getId()));
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("lastName", user.getLastName());

    xml.Save("Users.xml");
}
