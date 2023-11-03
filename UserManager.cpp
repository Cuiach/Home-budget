#include "UserManager.h"

int UserManager::getIdOfLoggedUser()
{
    return idOfLoggedUser;
}

bool UserManager::isUserLoggedIn()
{
    if (idOfLoggedUser > 0)
        return true;
    else
        return false;
}

void UserManager::changePasswordOfLoggedUser()
{
    if (idOfLoggedUser == 0)
        return;

    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AdditionalMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == idOfLoggedUser)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            cout << itr -> getPassword() << endl;
            cout << idOfLoggedUser << endl;
            system("pause");
        }
    }
    usersFile.writeAllUsersInFile(users);
}

int UserManager::logUserIn()
{
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AdditionalMethods::readLine();

    vector <User>::iterator itr = users.begin();

    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int tryCount = 3; tryCount > 0; tryCount--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << tryCount << ": ";
                password = AdditionalMethods::readLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idOfLoggedUser = itr -> getId();
                    system("pause");
                    return idOfLoggedUser;
                }

            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma Usera z takim loginem" << endl << endl;

    system("pause");
    return 0;
}

void UserManager::registerUser()
{
    User user = putNewUserDetails();

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::putNewUserDetails()
{
    User user;

    user.setId(getIdOfNewUser());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (loginExists(user.getLogin()));

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    string lastName;
    cout << "Podaj nazwisko: ";
    cin >> lastName;
    user.setLastName(lastName);

    return user;
}

int UserManager::getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::loginExists(string login)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::logUserOut()
{
    idOfLoggedUser = 0;
}
