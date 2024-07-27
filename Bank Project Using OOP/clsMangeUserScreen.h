#pragma once
#include "clsScreen.h";
#include "clsInputVaildation.h";
#include "clsBankClint.h";
#include "clsUserListScreen.h";
#include "clsAddUserScreen.h";
#include "clsDeleteUserScreen.h";
#include "clsUpdateScreen.h";
#include "clsFindUserScreen.h";

class clsMangeUserScreen: protected clsScreen
{
private:
	enum enUser
	{
		UserList = 1, addNewUser = 2,
		deleteUser = 3, updateUser = 4,
		findUser = 5, mainMenu = 6,
	};

	static void _UsersList()
	{
		//cout << "\nIt Will Be Here\n";
		clsUserListScreen::showUsersList();
	}

	static void _AddUser()
	{
		//cout << "\nIt Will Be Here\n";
		clsAddUserScreen::addNewClint();
	}

	static void _DeleteUser()
	{
		//cout << "\nIt Will Be Here\n";
		clsDeleteUserScreen::deleteClint();
	}

	static void _UpdateUser()
	{
		//cout << "\nIt Will Be Here\n";
		clsUpdateScreen::updateUser();
	}

	static void _FindUser()
	{
		//cout << "\nIt Will Be Here\n";
		clsFindUserScreen::FindUser();
	}

	static void _GetBackToUserManegmentMenu()
	{
		cout << "\n To Get Back To Transaction Menu ";
		system("pause");
		showUserManegmentMenu();
	}

	static short _readmangeUserOption()
	{
		short choise;
		cout << "\t\t\tChoose Number [1-6] :";
		choise = clsValidation::readShortNumberBetween(1, 6);
		return choise;
	}

	static void _PerformMangeUserChoies(enUser user)
	{
		system("cls");
		switch (user)
		{
		case clsMangeUserScreen::UserList:
		{
			_UsersList();
			_GetBackToUserManegmentMenu();
			break;
		}
		case clsMangeUserScreen::addNewUser:
		{
			_AddUser();
			_GetBackToUserManegmentMenu();
			break;
		}
		case clsMangeUserScreen::deleteUser:
		{
			_DeleteUser();
			_GetBackToUserManegmentMenu();
			break;
		}
		case clsMangeUserScreen::updateUser:
		{
			_UpdateUser();
			_GetBackToUserManegmentMenu();
			break;
		}
		case clsMangeUserScreen::findUser:
		{
			_FindUser();
			_GetBackToUserManegmentMenu();
			break;
		}
		case clsMangeUserScreen::mainMenu:
		{
			/*_UpdateUser();
			_GetBackToUserManegmentMenu();*/
			break;
		}
		}
	}
public:

	static void showUserManegmentMenu()
	{
		if (!checkAccessRights(clsBankUser::enUserPromissions::pUserMangment))
		{
			system("pause");
			return;//This Function Will Check User Permissions
		}
		system("cls");
		clsScreen::showHeaderMenu("  User Screen");
		cout << "\t\t\t\tUser Manegment Menu\n";
		cout << setw(40) << "\t\t\t_______________________________________" << endl;
		cout << "\t\t\t [1] Show Users List \n";
		cout << "\t\t\t [2] Add New User \n";
		cout << "\t\t\t [3] Delete User \n";
		cout << "\t\t\t [4] Update User Info \n";
		cout << "\t\t\t [5] Find User \n";
		cout << "\t\t\t [6] Main Menue \n";
		cout << setw(40) << "\t\t\t_______________________________________" << endl;

		_PerformMangeUserChoies((enUser)_readmangeUserOption());
	}
};

