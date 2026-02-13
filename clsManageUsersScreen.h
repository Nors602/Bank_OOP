#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class clsManageUsersScreen :protected clsScreen
{

private:
    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short ReadManageUsersMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenu()
    {
        cout << "\n\nPress any key to go back to Manage Users Menu...";
        system("pause>0");
        ShowManageUsersMenu();
    }

    static void _ShowListUsersScreen()
    {
		clsListUsersScreen::ShowUsersList();

    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();

    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();

    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformManageUsersMenuOption(enManageUsersMenueOptions ManageUsersMenuOption)
    {

        switch (ManageUsersMenuOption)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");

            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }



public:


    static void ShowManageUsersMenu()
    {
        if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenuOption((enManageUsersMenueOptions)ReadManageUsersMenuOption());
    }

};
