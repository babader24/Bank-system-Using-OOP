#pragma once
#include "clsScreen.h";
#include "clsBankClint.h";
#include "Global.h";

using namespace std;

class clsTransferScreen :protected clsScreen
{
private:

	static string _GetClint()
	{
		string AccountNumber = "";
		cout << "Please Enter Account Number : ";
		AccountNumber = clsValidation::readString();
		while (!clsBankClint::isClintExist(AccountNumber))
		{
			cout << "Clint Not Found, Please Enter a Valid One: ";
			AccountNumber = clsValidation::readString();
		}
		return AccountNumber;
	}

	static void _PrintClint(clsBankClint clint)
	{
		cout << "\n=================\n";
		cout << "   Clint Card\n";
		cout << "\n=================\n";
		cout << "Full Name  : " << clint.fullName() << endl;
		cout << "Acc.Number : " << clint.acountNumber() << endl;
		cout << "Balance    : " << clint.AcountBalance << endl;
		cout << "_______________________________\n";
	}
public:

	static void showTransferScreen()
	{
		clsScreen::showHeaderMenu("Transfers Screen");

		string account1 = _GetClint();
		clsBankClint clint1 = clsBankClint::Find(account1);
		_PrintClint(clint1);

		string account2 = _GetClint();
		clsBankClint clint2 = clsBankClint::Find(account2);
		_PrintClint(clint2);

		if (clsBankClint::transfer(clint1, clint2, currntUser.GetUserName()))
		{
			_PrintClint(clint1);	
			_PrintClint(clint2);
		}
		else
		{
			cout << "No";
		}

	}
};

