#pragma once
#include "clsBankClint.h";
#include "clsScreen.h";
#include <iostream>
#include "clsInputVaildation.h";

using namespace std;

class clsUpdateClintScreen : protected clsScreen
{
private:
	static void _ReadClintInfo(clsBankClint& clint)
	{
		cout << "\nEnter First Name: ";
		clint.firstName = clsValidation::readString();

		cout << "\nEnter last Name: ";
		clint.lastName = clsValidation::readString();

		cout << "\nEnter email: ";
		clint.email = clsValidation::readString();

		cout << "\nEnter phone: ";
		clint.phone = clsValidation::readString();

		cout << "\nEnter pincode: ";
		clint.pincode = clsValidation::readString();

		cout << "\nEnter Acount Balance: ";
		clint.AcountBalance = clsValidation::readFloatNumber();
	}

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


	static void updateClint()
	{
		if (!checkAccessRights(clsBankUser::enUserPromissions::pUpdateCilnt))
		{
			return;//This Function Will Check User Permissions
		}
		clsScreen::showHeaderMenu("Update Clint");

		string AccountNumber = "";
		cout << "please Enter Clint Account Number: ";
		AccountNumber = clsValidation::readString();
		while (!clsBankClint::isClintExist(AccountNumber))
		{
			cout << "Account Is Not Found, Please Enter Another One: ";
			AccountNumber = clsValidation::readString();
		}
		clsBankClint clint = clsBankClint::Find(AccountNumber);
		_PrintClint(clint);
		if (clsValidation::readAnswer())
		{
			cout << "Update Clint Info: ";
			cout << "\n_______________________\n";
			_ReadClintInfo(clint);

			clsBankClint::enSaveResult saveResult;
			saveResult = clint.save();

			switch (saveResult)
			{
			case clsBankClint::svFaildEmptyObject:
			{
				cout << "\nError Account Was Not Saved Because Its Empty \n";
				break;
			}
			case clsBankClint::svSuccessed:
			{
				cout << "\nAccount updated Successfuly :-) \n";
				_PrintClint(clint);
				break;
			}
			}
		}
		else
		{
			cout << "Error, Clint Was Not Updated  ";
		}
	}
};

