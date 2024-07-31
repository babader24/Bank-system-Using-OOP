#pragma once
#include "clsScreen.h";
#include <iostream>
#include "clsClintList.h";
#include "clsAddClintScreen.h";
#include "clsDeleteClintScreen.h";
#include "clsUpdateClintScreen.h";
#include "clsFindClint.h";
#include "clsShowTransactionScreen.h";
#include "clsMangeUserScreen.h";
//#include "clsEndScreen.h";
#include "clsLoginScreen.h";
#include "Global.h";
#include "clsLoginRegesterScreen.h";
#include "clsCurrencyMainScreen.h";

using namespace std;
class clsShowScreens :protected clsScreen
{
private:
	enum enChoseOption
	{
		showClintList = 1, showAddNewClint = 2,
		showDeleteClint = 3, showUpdateCilnt = 4,
		showFindClint = 5, showTransection = 6,
		showUserMangment = 7, showRegester = 8,
		showCurrencyScreen = 9, showExit = 10
	};

	static short _readOptionNumber()
	{
		short choise;
		cout << "\t\t\tChoose Number [1-10] :";
		choise = clsValidation::readShortNumberBetween(1, 10);
		return choise;
	}

	static void _GetBackToMainMenu()
	{
		cout << "\n To Get Back To Main Menu ";
		system("pause");
		showMainMenu();
	}

	static void _clintList()
	{	
		//cout << "\nIt Will Be Here\n";
		clsClintList::showClintsList();
	}

	static void _AddClint()
	{
		//cout << "\nIt Will Be Here\n";
		clsAddClintScreen::addNewClint();
	}

	static void _DeleteClint()
	{
		//cout << "\nIt Will Be Here\n";
		clsDeleteClintScreen::deleteClint();
	}

	static void _UpdateClint()
	{
		//cout << "\nIt Will Be Here\n";
		clsUpdateClintScreen::updateClint();
	}

	static void _FindClint()
	{
		//cout << "\nIt Will Be Here\n";
		clsFindClint::findClint();
	}

	static void _Transactions()
	{
		//cout << "\nIt Will Be Here\n";
		clsShowTransactionScreen::showTransactionScreen();
	}

	static void _UserMangemenet()
	{
		//cout << "\nIt Will Be Here _UserMangemenet\n";
		clsMangeUserScreen::showUserManegmentMenu();
	}

	/*static void _EndScreen()
	{
		//cout << "\nIt Will Be Here _EndScreen\n";
		clsEndScreen::showEndScreen();
	}*/

	static void _ShowCurrencyMainScreen()
	{
		clsCurrencyMainScreen::showCurrencyMainScreen();
	}

	static void _Logout()
	{
		currntUser = clsBankUser::Find("", "");
	}

	static void _showRegestrScreen()
	{
		clsLoginRegesterScreen::showRegesterScreen();
	}

	static void _PerformAction(enChoseOption option)
	{
		system("cls");

		switch (option)
		{
		case clsShowScreens::showClintList:
		{
			_clintList();
			_GetBackToMainMenu();
			break;
		}
		case clsShowScreens::showAddNewClint:
		{
			_AddClint();
			_GetBackToMainMenu();
			break;
		}
		case clsShowScreens::showDeleteClint:
		{
			_DeleteClint();
			_GetBackToMainMenu();
			break;
		}
		case clsShowScreens::showUpdateCilnt:
		{
			_UpdateClint();
			_GetBackToMainMenu();
			break;
		}
		case clsShowScreens::showFindClint:
		{
			_FindClint();
			_GetBackToMainMenu();
			break;
		}
		case clsShowScreens::showTransection:
		{
			_Transactions();
			showMainMenu();
			break;
		}
		case clsShowScreens::showUserMangment:
		{
			_UserMangemenet();
			showMainMenu();
			break;
		}
		case clsShowScreens::showRegester:
		{
			_showRegestrScreen();
			_GetBackToMainMenu();
			break;
		}
		case clsShowScreens::showCurrencyScreen:
		{
			_ShowCurrencyMainScreen();
			showMainMenu();
			break;
		}
		case clsShowScreens::showExit:
		{
			_Logout();
			break;
		}
		}
	}

public:

	static void showMainMenu()
	{
		system("cls"); 
		clsScreen::showHeaderMenu("   Main Screen");
		cout << "\t\t\t\t\t\Main Menu\n";
		cout << setw(40) << "\t\t\t_______________________________________" << endl;
		cout << "\t\t\t [1] Show Clint List \n";
		cout << "\t\t\t [2] Add New Clint \n";
		cout << "\t\t\t [3] Delete Clint \n";
		cout << "\t\t\t [4] Update Clint Info \n";
		cout << "\t\t\t [5] Find Clint \n";
		cout << "\t\t\t [6] Transection \n";
		cout << "\t\t\t [7] User Mangement \n";
		cout << "\t\t\t [8] Login Regesters List \n";
		cout << "\t\t\t [9] Show Currency Screen \n";
		cout << "\t\t\t [10] LogOut \n";
		cout << setw(40) << "\t\t\t________________________________________" << endl;
		_PerformAction((enChoseOption)_readOptionNumber());
	}
};

