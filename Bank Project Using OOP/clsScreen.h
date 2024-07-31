#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankUser.h";
#include "Global.h";
#include "clsDate.h";


using namespace std;

class clsScreen
{
protected:
	static void showHeaderMenu(string title, string SubTitle = "")
	{
		cout << setw(40) << "\t\t\t_______________________________________" << endl;
		cout << "\t\t\t\t   " << title << "\n";
		if (SubTitle != "")
		{
			cout << "\t\t\t\t   "  << SubTitle << "\n";
		}
		cout << setw(40) << "\t\t\t_______________________________________" << endl;
		cout << "\t\t\tUser : " << currntUser.GetUserName() << "\n";
		cout << "\t\t\tDate : " << clsDate::dateToString(clsDate()) << endl;
		cout << setw(40) << "\t\t\t_______________________________________" << endl;

	}

	static bool checkAccessRights(clsBankUser::enUserPromissions permission)
	{
		if (currntUser.checkAccessPermissions(permission))
		{
			return true;
		}
		else
		{
			cout << setw(40) << "\t\t\t_______________________________________" << endl;
			cout << "\t\t\t  Acces Denied! Contact Your Admin. \n";
			cout << setw(40) << "\t\t\t_______________________________________" << endl;
			return false;
		}
	}
};

