#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsFindCurrencyScreen : protected clsScreen
{
	enum enFindCurrency{eByCode = 1 , eByCountry = 2};
	static enFindCurrency _ReadHowCurrencyFind()
	{
		cout << "Find By [1] Code or [2] Country : ";
		return (enFindCurrency)clsInputValidate::ReadIntNumberBetween(1, 2, "Enter 1 or 2 only\n");
    }
	static void _PrintCurrencyCard( const clsCurrency &Currency)
	{
		cout << "\tCurrency Card \n";
		cout << "_________________________\n";
		cout << "Country : " << Currency.Country() << endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Name    : " << Currency.CurrencyName() << endl;
		cout << "Rate 1$ : " << Currency.Rate() << endl;
		cout << "_________________________\n";
	}
	static string _ReadCurrencyCode()
	{
		cout << "Enter Currency Code : ";
		return  clsInputValidate::ReadString();
	}
	static string _ReadCurrencyCountry()
	{
		cout << "Enter Currency Country : ";
		return clsInputValidate::ReadString();
	}
	static void _ShowResult( clsCurrency  &Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found =) \n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Not Found (= \n";
		}

	}
	static clsCurrency _FindCurrency (enFindCurrency Find )
	{
		if(Find == enFindCurrency::eByCode)
		{
			string CurrencyCode = _ReadCurrencyCode();
			return clsCurrency::FindByCode(CurrencyCode);
		}
		else
		{
			string Country = _ReadCurrencyCountry();
			return clsCurrency::FindByCountry(Country);
		}
	}
	
public :
	static void ShowCurrencyFindScreen()
	{
		_DrawScreenHeader("\t Find Currency");
		clsCurrency Currency = _FindCurrency(_ReadHowCurrencyFind());
		_ShowResult(Currency);
	}
};