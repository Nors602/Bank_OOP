#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsBankClient.h"
#include "clsClientListScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsUsers.h"
#include "Global.h"
#include "clsLoginRegister.h"
using namespace std;
class clsMainScreen : protected  clsScreen
{
private :
	enum enMainMenuOptions {  ShowClientsList = 1,  AddNewClient = 2 , DeleteClient = 3, UpdateClient = 4
		                     , FindClient = 5, Transactions = 6, MangeUser = 7,eLoginRegister=8, Exit = 9};
	
	

	static void _GoBackToMainMenu()
	{
		cout << "\nPress any key to go back to main menu ...";
		system("pause>0");
		ShowMainMenu();
	}
    static void _ShowClientsList()
	{
		clsClientListScreen::ShowClientsList();
	}
	static void _AddNewClient()
	{
		clsAddNewClient::ShowAddNewClientScreen();
	}
	static void _DeleteClient()
	{
		clsDeleteClient::ShowDeleteClientScreen();
	}
	static void _UpdateClient()
	{
		clsUpdateClient::ShowUpdateClientScreen();
	}
	static void _FindClient()
			{
		clsFindClient::ShowFindClientScreen();
			}
	static void _Transactions()
		{
		clsTransactionScreen::ShowTransactionsMenue();
		}
	static void _MangeUser()
		{
		clsManageUsersScreen::ShowManageUsersMenu();
		}
	static void _ShowLoginRegister()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	/*static void _Exit()
		{
			cout << "\nExit Screen.";
		}*/
	static void _Logout()
	{
		CurrentUser = clsUser::Find("","");
	}
	static short _ReadMainMenuOption()
	{
		cout << "\nPlease choose what do you want to do? [1 to 9] : ";
		return clsInputValidate::ReadIntNumberBetween(1, 9, "Enter Number between [1] and [9] again : ");
	}
	static enMainMenuOptions _PerformMainMenuOption(short MainMenuOption )
	{
		switch (MainMenuOption)
		{
		case enMainMenuOptions::ShowClientsList:
		
			system("cls");
			_ShowClientsList();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::AddNewClient:
			
			system("cls");
			_AddNewClient();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::DeleteClient:
			
			system("cls");
			_DeleteClient();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::UpdateClient:
			
			system("cls");
			_UpdateClient();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::FindClient:
			
			system("cls");
			_FindClient();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::Transactions:
			
			system("cls");
			_Transactions();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::MangeUser:
			
			system("cls");
			_MangeUser();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eLoginRegister :
			system("cls");
			_ShowLoginRegister();
			_GoBackToMainMenu();
		case enMainMenuOptions::Exit:
			system("cls");
			_Logout();
			break;
		default:
			cout << "\nError Main Menu Option is not valid.\n";
			break;
		}
		return (enMainMenuOptions)MainMenuOption;
	}
public :
	  static  void ShowMainMenu()
	  {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformMainMenuOption(_ReadMainMenuOption());
	}
};