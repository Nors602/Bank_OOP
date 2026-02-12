#pragma once
#include "clsUsers.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
using namespace std;
class clsFindUserScreen : protected clsScreen
{
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }
public :
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t Find User Screen");
        string UserName = "";
        cout << "Enter User Name : ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "User by User Name : <" << UserName << "> Not Found Enter Another Choice : ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::Find(UserName);
       
       
    }
};

