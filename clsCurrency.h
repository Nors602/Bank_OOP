#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "clsString.h"
#include "fstream"
using namespace std;
class clsCurrency
{
 enum enMode {eEmpty = 1 , eUpdate= 2};
 enMode _Mode;
 string _Country;
 string _CurrencyCode;
 string _CurrencyName;
 float _Rate;


 static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separetor = "#//#")
 {
	 vector <string> vCurrencyData = clsString::Split(Line, Separetor);
	 return clsCurrency(enMode::eUpdate, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
 }

 static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separetor = "#//#")
 {
	 string DataLine; 
	 DataLine += Currency.Country() + Separetor;
	 DataLine += Currency.CurrencyCode() + Separetor;
	 DataLine += Currency.CurrencyName() + Separetor;
	 DataLine += to_string(Currency.Rate());
	 return DataLine;
 }

 static vector<clsCurrency> _LoadCurrenciesDataFromFile()
 {
	 vector<clsCurrency> vCurrencies;
	 fstream MyFile;
	 MyFile.open("Currencies.txt", ios::in);
	 if (MyFile.is_open())
	 {
		 string Line;
		 while (getline(MyFile, Line))
		 {
			 vCurrencies.push_back(_ConvertLineToCurrencyObject(Line));
		 }
		 MyFile.close();
	 }
	 return vCurrencies;
 }
 
 static void _SaveCurrenciesDataToFile(vector<clsCurrency> vCurrencies)
 {
	 fstream MyFile;
	 MyFile.open("Currencies.txt", ios::out);
	 if (MyFile.is_open())
	 {
		 for (clsCurrency Currency : vCurrencies)
		 {
			 MyFile << _ConvertCurrencyObjectToLine(Currency) << endl;
		 }
		 MyFile.close();
	 }
 }
 
 void _UpdateCurrencyInFile(clsCurrency Currency)
 {
	 vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();
	 for (clsCurrency& C : vCurrencies)
	 {
		 if (C.CurrencyCode() == Currency.CurrencyCode())
		 {
			 C = *this;
			 break;
		 }
	 }
	 _SaveCurrenciesDataToFile(vCurrencies);
 }
 
 static clsCurrency _GetEmptyCurrencyObject()
 {
	 return clsCurrency(enMode::eEmpty, "", "", "", 0);
 }

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	string Country() const { return _Country; }
	string CurrencyCode() const { return _CurrencyCode; }
	string CurrencyName() const { return _CurrencyName; }
	float Rate() const { return _Rate; }
	void Rate(float NewRate)
	{
		if (_Mode == enMode::eUpdate)
		{
			_Rate = NewRate;
			_UpdateCurrencyInFile(*this);
		}
	}
	bool IsEmpty() const { return _Mode == enMode::eEmpty; }
	static vector <clsCurrency> GetAllUSDRates()
	{
		return _LoadCurrenciesDataFromFile();
	}

	static   clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();
		for (clsCurrency Currency : vCurrencies)
		{
			if (clsString::UpperAllString(Currency.CurrencyCode()) == CurrencyCode)
			{
				return Currency;
			}
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();
		for (clsCurrency Currency : vCurrencies)
		{
			if (clsString::UpperAllString(Currency.Country()) == Country)
			{
				return Currency;
			}
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);
		return !Currency.IsEmpty();
	}

	
};

