#pragma once
#include "clsScreen.h";
#include "clsBankUser.h";
#include <iomanip>

class clsUserListScreen: protected clsScreen
{
private:
	static void _PrintUser(clsBankUser User)
	{
		cout << "|" << left << setw(15) << User.GetUserName();
		cout << "|" << left << setw(20) << User.fullName();
		cout << "|" << left << setw(25) << User.email;
		cout << "|" << left << setw(15) << User.phone;
		cout << "|" << left << setw(10) << User.password;
		cout << "|" << left << setw(10) << User.permissions << endl;
	}

public:
	static void showUsersList()
	{
		vector <clsBankUser> vClint = clsBankUser::getUserRecord();
		string title = "User Screen";
		string subTitle = "(" + to_string(vClint.size()) + ") User's";

		clsScreen::showHeaderMenu(title, subTitle);

		cout << setw(70) << "_______________________________________________________________________________________________________\n";
		cout << "                                   User List\n";
		cout << setw(70) << "_______________________________________________________________________________________________________\n";
		cout << "|" << left << setw(15) << "User Name";
		cout << "|" << left << setw(20) << "FullName";
		cout << "|" << left << setw(25) << "Email";
		cout << "|" << left << setw(15) << "PhoneNumber";
		cout << "|" << left << setw(10) << "Password";
		cout << "|" << left << setw(10) << "permissions" << endl;
		cout << setw(70) << "_______________________________________________________________________________________________________\n";

		if (vClint.size() == 0)
		{
			cout << "\t\t\tNo Clint Avalibale.\n";
		}
		for (clsBankUser& c : vClint)
		{
			_PrintUser(c);
		}
		cout << setw(70) << "_______________________________________________________________________________________________________\n";
	}
};

