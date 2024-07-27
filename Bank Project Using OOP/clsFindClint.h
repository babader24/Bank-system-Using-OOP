#pragma once
#include "clsScreen.h";
#include "clsBankClint.h";
#include "clsInputVaildation.h";

class clsFindClint : protected clsScreen
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

	static void findClint()
	{
		if (!checkAccessRights(clsBankUser::enUserPromissions::pFindClint))
		{
			return;//This Function Will Check User Permissions
		}
		clsScreen::showHeaderMenu("Find Clint");
		cout << "Please Enter Account Number : ";
		string AccountNumber = clsValidation::readString();

		while (!clsBankClint::isClintExist(AccountNumber))
		{
			cout << "Clint Not Found, Please Enter a Valid One: ";
			AccountNumber = clsValidation::readString();
		}

		clsBankClint clint = clsBankClint::Find(AccountNumber);

		if (clint.isEmpty())
		{
			cout << "\nClint Is Empty\n";
		}
		else
		{
			cout << "\nClint Is Found :-)\n";
			_PrintClint(clint);
		}

	}
};

