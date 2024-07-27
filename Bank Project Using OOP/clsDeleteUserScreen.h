#pragma once
#include "clsScreen.h";
#include "clsBankUser.h";
#include "clsInputVaildation.h";

using namespace std;

class clsDeleteUserScreen : protected clsScreen
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
	static void deleteClint()
	{
		clsScreen::showHeaderMenu("Delete user");

		string AccountNumber = "";
		cout << "Please Enter User Name : ";
		AccountNumber = clsValidation::readString();
		while (!clsBankUser::isUserExsit(AccountNumber))
		{
			cout << "User Not Found, Please Enter a Valid One: ";
			AccountNumber = clsValidation::readString();
		}

		clsBankUser user = clsBankUser::Find(AccountNumber);
		_PrintUser(user);

		if (clsValidation::readAnswer())
		{
			if (user.DeleteUser())
			{
				cout << "user Deleted Successfuly :-) ";
				_PrintUser(user);
			}
		}
		else
		{
			cout << "Error, user Was Not Deleted  ";
		}
	}
};

