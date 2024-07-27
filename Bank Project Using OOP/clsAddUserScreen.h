#pragma once
#include "clsScreen.h";
#include "clsInputVaildation.h";
#include "clsBankUser.h";

class clsAddUserScreen :protected clsScreen
{
private:

	static clsBankUser _ReadClintInfo(clsBankUser& clint)
	{


		cout << "\nEnter First Name: ";
		clint.firstName = clsValidation::readString();

		cout << "\nEnter last Name: ";
		clint.lastName = clsValidation::readString();

		cout << "\nEnter email: ";
		clint.email = clsValidation::readString();

		cout << "\nEnter phone: ";
		clint.phone = clsValidation::readString();

		cout << "\nEnter password: ";
		clint.password = clsValidation::readString();

		cout << "\nEnter permissions: ";
		clint.permissions = _ReadPermissons();
		return clint;
	}

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

	static short _ReadPermissons()
	{
		short counter = 0;
		cout << "Do You Want To Give Him Full Access? ";
		if (clsValidation::readYesOrNo())
		{
			return -1;
		}
		else
		{
			cout << "\nDo You Want To Give Him Show List Clint? y/Y ";
			(clsValidation::readYesOrNo()) ? counter |= clsBankUser::enUserPromissions::pShowClintList : 0;

			cout << "\nDo You Want To Give Him add New Clint? y/Y ";
			(clsValidation::readYesOrNo()) ? counter |= clsBankUser::enUserPromissions::pAddNewClint : 0;

			cout << "\nDo You Want To Give Him delete Clint? y/Y ";
			(clsValidation::readYesOrNo()) ? counter |= clsBankUser::enUserPromissions::pDeleteClint : 0;

			cout << "\nDo You Want To Give Him find Clint? y/Y ";
			(clsValidation::readYesOrNo()) ? counter |= clsBankUser::enUserPromissions::pFindClint : 0;

			cout << "\nDo You Want To Give Him transection? y/Y ";
			(clsValidation::readYesOrNo()) ? counter |= clsBankUser::enUserPromissions::pTransection : 0;

			cout << "\nDo You Want To Give Him update Cilnt? y/Y ";
			(clsValidation::readYesOrNo()) ? counter |= clsBankUser::enUserPromissions::pUpdateCilnt : 0;

			cout << "\nDo You Want To Give Him user Mangment? y/Y ";
			(clsValidation::readYesOrNo()) ? counter |= clsBankUser::enUserPromissions::pUserMangment : 0;
		}
		return counter;
	}
public:

	static void addNewClint()
	{
		clsScreen::showHeaderMenu("Add New User");

		string AccountNumber = "";
		cout << "please Enter User Account Number: ";
		AccountNumber = clsValidation::readString();
		while (clsBankUser::isUserExsit(AccountNumber))
		{
			cout << "Account Is Already Exist, Please Enter Another One: ";
			AccountNumber = clsValidation::readString();
		}
		clsBankUser User = clsBankUser::addNewUser(AccountNumber);
		_ReadClintInfo(User);

		clsBankUser::enSaveResult saveResult;
		saveResult = User.SaveUser();

		switch (saveResult)
		{
		case clsBankUser::svFaildEmptyObject:
			cout << "Error, Empty Object";
			break;
		case clsBankUser::svSuccessed:
			cout << "User Added Successfuly ";
			_PrintUser(User);
			break;
		case clsBankUser::svFaileAccountExist:
			cout << "Error, User Already Exist! ";
			break;
		}
	}
};

