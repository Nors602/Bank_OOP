#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;
class clsUpdateCurrencyRateScreen : protected clsScreen
{
	static void _PrintCurrencyCard(const clsCurrency& Currency)

	{
		cout << "\tCurrency Card \n";
		cout << "_________________________\n";
		cout << "Country : " << Currency.Country() << endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Name    : " << Currency.CurrencyName() << endl;
		cout << "Rate 1$ : " << Currency.Rate() << endl;
		cout << "_________________________\n";
	}

	static float ReadNewCurrencyRate()
	{
		cout << "Enter New Rate For 1$ : ";
		return clsInputValidate::ReadFloatNumber();
	}

	static string ReadCurrencyCode()
	{
		cout << "Enter Currency Code : ";
		return clsInputValidate::ReadString();
	}

	static char ReadAnswer()
	{
		char Answer;
		do
		{
			cout << "Are you sure do you want to update this currency rate ? [Y/N] : ";
			
			cin >> Answer;
		} while (tolower(Answer) != 'y' && tolower(Answer) != 'n');
		return tolower(Answer);
	}

public :

	static void ShowUpdateCurrencyRateScreen()
	{
		
		_DrawScreenHeader("\t\tUpdate Currency Rate Screen");

		string CurrencyCode = ReadCurrencyCode();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Currency Code is not exist, Enter another one : ";
			CurrencyCode = ReadCurrencyCode();
		}

		clsCurrency Currency  = clsCurrency::FindByCode(CurrencyCode);

		float OldRate = Currency.Rate();

		_PrintCurrencyCard(Currency);

		char Answer = ReadAnswer();

		if(Answer == 'y')
		{
			float NewRate = ReadNewCurrencyRate();

			Currency.Rate(NewRate);

			cout << "\nUpdated Currency Rate is  Successfully ;)\n\n";
			_PrintCurrencyCard(Currency);	

			cout << "\nThe Old Rate was : " << OldRate << endl;
			cout << "The New Rate is : " << Currency.Rate() << endl;

		}
		else
		{
			cout << "\nCurrency Rate Update Cancelled :(\n";
		}
	
	}
};

