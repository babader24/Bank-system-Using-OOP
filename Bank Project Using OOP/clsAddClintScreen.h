#pragma once
#pragma once
#include "clsScreen.h";
#include "clsInputVaildation.h";
#include <iostream>;
#include "clsClintList.h";
#include "clsPerson.h";
class clsAddClintScreen :protected clsScreen
{
private:
	static clsBankClint _ReadClintInfo(clsBankClint& clint)
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
		return clint;
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

	static void addNewClint()
	{
		if (!checkAccessRights(clsBankUser::enUserPromissions::pAddNewClint))
		{
			return;//This Function Will Check User Permissions
		}
		clsScreen::showHeaderMenu("Add New Clint");

		string AccountNumber = "";
		cout << "please Enter Clint Account Number: ";
		AccountNumber = clsValidation::readString();
		while (clsBankClint::isClintExist(AccountNumber))
		{
			cout << "Account Is Already Ecist, Please Enter Another One: ";
			AccountNumber = clsValidation::readString();
		}
		clsBankClint clint = clsBankClint::addNewClint(AccountNumber);
		_ReadClintInfo(clint);

		clsBankClint::enSaveResult saveResult;
		saveResult = clint.save();

		switch (saveResult)
		{
		case clsBankClint::svFaildEmptyObject:
			cout << "Error, Empty Object";
			break;
		case clsBankClint::svSuccessed:
			cout << "Clint Added Successfuly ";
			_PrintClint(clint);
			break;
		case clsBankClint::svFaileAccountExist:
			cout << "Error, Clint Already Exist! ";
			break;
		default:
			break;
		}
	}
};

