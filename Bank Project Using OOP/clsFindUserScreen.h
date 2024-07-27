#pragma once
#include "clsScreen.h";
#include "clsBankUser.h";
#include "clsInputVaildation.h";
using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsBankUser clint)
	{
		cout << "\n=================\n";
		cout << "   Clint Card\n";
		cout << "\n=================\n";
		cout << "User Name    : " << clint.GetUserName() << endl;
		cout << "Full Name    : " << clint.fullName() << endl;
		cout << "Email        : " << clint.email << endl;
		cout << "Phone        : " << clint.phone << endl;
		cout << "Password     : " << clint.password << endl;
		cout << "Permissions  : " << clint.permissions << endl;
		cout << "_______________________________\n";
	}

public:

	static void FindUser()
	{
		clsScreen::showHeaderMenu("Update user");

		string AccountNumber = "";
		cout << "Please Enter User Name : ";
		AccountNumber = clsValidation::readString();
		while (!clsBankUser::isUserExsit(AccountNumber))
		{
			cout << "User Not Found, Please Enter a Valid One: ";
			AccountNumber = clsValidation::readString();
		}

		clsBankUser user = clsBankUser::Find(AccountNumber);

		if (user.isEmpty())
		{
			cout << "\nError, User Is Empty\n";
		}
		else
		{
			cout << "\nUser Found :-) \n";
			_PrintUser(user);
		}
	}
};

