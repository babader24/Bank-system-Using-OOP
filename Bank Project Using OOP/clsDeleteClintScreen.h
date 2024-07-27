#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankClint.h";

using namespace std; 

class clsDeleteClintScreen : protected clsScreen
{
private:
	static void _PrintClint(clsBankClint clint)
	{
		cout << "\n=================\n";
		cout << "   Clint Card\n";
		cout << "\n=================\n";
		cout << "First Name : " << clint.firstName << endl;
		cout << "Last Name  : " << clint.lastName << endl;
		cout << "Full Name  : " << clint.fullName() << endl;
		cout << "Email      : " << clint.email << endl;
		cout << "Phone      : " << clint.phone << endl;
		cout << "Acc.Number : " << clint.acountNumber() << endl;
		cout << "Password   : " << clint.pincode << endl;
		cout << "Balance    : " << clint.AcountBalance << endl;
		cout << "_______________________________\n";
	}
public:

	static void deleteClint()
	{
		if (!checkAccessRights(clsBankUser::enUserPromissions::pDeleteClint))
		{
			return;//This Function Will Check User Permissions
		}
		clsScreen::showHeaderMenu("Delete Clint");

		string AccountNumber = "";
		cout << "Please Enter Account Number : ";
		AccountNumber = clsValidation::readString();
		while (!clsBankClint::isClintExist(AccountNumber))
		{
			cout << "Clint Not Found, Please Enter a Valid One: ";
			AccountNumber = clsValidation::readString();
		}

		clsBankClint clint = clsBankClint::Find(AccountNumber);
		_PrintClint(clint);

		if (clsValidation::readAnswer())
		{
			if (clint.Delete())
			{
				cout << "Clint Deleted Successfuly :-) ";
				_PrintClint(clint);
			}
		}
		else
		{
			cout << "Error, Clint Was Not Deleted  ";
		}
	}
};

