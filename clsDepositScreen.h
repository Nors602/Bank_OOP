#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;

class clsDeposit : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}
	public:
	static void ShowDepositScreen()
	{
		clsScreen::_DrawScreenHeader("\t    Deposit Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Client With [" << AccountNumber << "\ does not found , try again . \n";
			string AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Ammount = 0;
		cout << "\nPlease Enter deposit Ammount ? ";
		Ammount  = clsInputValidate::ReadDblNumber();

		cout << "Are you sure you want to performs Tranasactions ? y/n . ";
		char Answer;
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Client1.Deposit(Ammount);
			cout << "Ammount Deposit succesfully .\n";
			cout << "New Balance is : " << Client1.AccountBalance << " $.";
		}
		else
		{
			cout << "\nOperation was canelled . \n";
		}

	}
};



