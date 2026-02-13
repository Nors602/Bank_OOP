#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsers.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;
class clsCurrencyScreen : protected clsScreen
{
	
	enum enCurrencyMenuOptions { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculeter = 4, eMainMenu = 5 };
	static void _ShowCurrencyListScreen()
	{
		clsCurrencyListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowCurrencyFindScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculeterScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void GoBackToCurrencyMenu()
	{
		system("pause");
		ShowCurrencyMenu();
	}

	static int _ReadCurrencyMenuOption()
	{
		cout << "\nPlease choose what do you want to do? [1 to 5] : ";
		return clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between [1] and [5] again : ");
	}

	static enCurrencyMenuOptions _PerformCurrencyMenuOption(enCurrencyMenuOptions Option)
	{
		switch (Option)
		{
		case enCurrencyMenuOptions::eListCurrencies:
			system("cls");
			_ShowCurrencyListScreen();
			GoBackToCurrencyMenu();
			break;
		case enCurrencyMenuOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			GoBackToCurrencyMenu();
			break;
		case enCurrencyMenuOptions::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			GoBackToCurrencyMenu();
			break;
		case enCurrencyMenuOptions::eCurrencyCalculeter:
			system("cls");
			_ShowCurrencyCalculeterScreen();
			GoBackToCurrencyMenu();
			break;
		case enCurrencyMenuOptions::eMainMenu:
			break;
		default:
			cout << "\n\n\t\t\t\t\tWrong Choice, Try Again . . .\n";
			system("pause");
			ShowCurrencyMenu();
			break;
		}
		return enCurrencyMenuOptions::eMainMenu;
	}

public :
	static void ShowCurrencyMenu()
	{
		if (clsScreen::CheckAccessRights(clsUser::enPermissions::pCurrencyScreen) == false)
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t\Currency Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List All Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency .\n";
		cout << setw(37) << left << "" << "\t[3] Update Currency Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculteter.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		_PerformCurrencyMenuOption(enCurrencyMenuOptions(_ReadCurrencyMenuOption()));
	}

};

