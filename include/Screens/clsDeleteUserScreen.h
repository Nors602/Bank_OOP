#pragma once
#include "clsUsers.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
using namespace std;
class clsDeleteUserScreen : protected clsScreen
{
	static string _ReadUserName()
	{
		string UserName;
		cout << "\nPlease enter user name? ";
		cin >> UserName;
		return UserName;
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

public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t  Delete User Screen");
		string UserName = _ReadUserName();
		clsUser User = clsUser::Find(UserName);
		if (User.IsEmpty())
		{
			cout << "\nUser Not Found :-(";
		}
		else
		{
			_PrintUser(User);
			cout << "\nAre you sure you want to delete this user? y/n? ";
			char Answer;
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{
				User.Delete();
				cout << "\nUser Deleted Successfully :-)\n";
			}
			else
			{
				cout << "\nDelete Operation Cancelled :-)\n";
			}
		}
	}
};

