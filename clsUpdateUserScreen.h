#pragma once
#include "clsUsers.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
using namespace std;

class clsUpdateUserScreen: protected clsScreen
{
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

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

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }
    public:
        static void ShowUpdateUserScreen()
        {
            _DrawScreenHeader("\t Update User Screen");
            string UserName = "";
            cout << "Enter User Name : ";
            UserName = clsInputValidate::ReadString();
            while (!clsUser::IsUserExist(UserName))
            {
                cout << "User by User Name : <" << UserName << "> Not Found Enter Another Choice : ";
                UserName = clsInputValidate::ReadString();
            }
            clsUser User = clsUser::Find(UserName);
            _PrintUser(User);
            cout << "Are You Sure do you want Update User : ? y/n .";
            char Answer; cin >> Answer;
            if (tolower(Answer) == 'y')
            {
                _ReadUserInfo(User);
                clsUser::enSaveResults SaveResult = User.Save();
                switch (SaveResult)
                {
                case clsUser::svFaildEmptyObject:
					cout << "\nUser object is empty -)\n";    
                    break;
                case clsUser::svSucceeded:
					cout << "\nUser Updated Successfully :-)\n";
					_PrintUser(User);
                  
                    break;
                case clsUser::svFaildUserExists:
                    break;
               
                }
               
            }
            else
            {
				cout << "\nUpdate User Operation Cancelled :-)\n";
            }
        }
};

