#pragma once
#include <iostream>
#include "clsScreen.h";
#include <iomanip>
#include "clsInputVaildation.h";
#include "clsDepositeClint.h";
#include "clsWithdrawClint.h";
#include "clsTotalBalancesScreen.h";
#include "clsTransferScreen.h";
#include "clsTransferLogScreen.h";


class clsShowTransactionScreen : protected clsScreen
{
private:
	enum enTransactionCoies
	{
		deposite = 1, withDraw = 2,
		TotaleBalane = 3, TransferScreen = 4,
		TransferLog = 5, MainMenu = 6

	};

	static void _ShowDeposite()
	{
		//cout << "\nIt Will Be Here _ShowDeposite\n";
		clsDepositeClint::deposteClint();
	}

	static void _ShowWithDraw()
	{
		//cout << "\nIt Will Be Here _ShowWithDraw\n";
		clsWithdrawClint::deposteClint();
	}

	static void _ShowTotaleBalane()
	{
		//cout << "\nIt Will Be Here _ShowTotaleBalane\n";
		clsTotalBalancesScreen::showTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::showTransferScreen();
	}

	static void _ShowtransfersLogScreen()
	{
		clsTransferLogScreen::showTransferLogScreen();
	}

	static void _GetBackToTransactionMenu()
	{
		cout << "\n To Get Back To Transaction Menu ";
		system("pause");
		showTransactionScreen();
	}

	static short _readOptionNumber()  
	{
		short choise;
		cout << "\t\t\tChoose Number [1-6] :";
		choise = clsValidation::readShortNumberBetween(1, 6);
		return choise;
	}

	static void _PerformChoies(enTransactionCoies Tchoies)
	{
		system("cls");
		switch (Tchoies)
		{
		case clsShowTransactionScreen::deposite:
		{
			_ShowDeposite();
			_GetBackToTransactionMenu();
			break;
		}
		case clsShowTransactionScreen::withDraw:
		{
			_ShowWithDraw();
			_GetBackToTransactionMenu();
			break;
		}
		case clsShowTransactionScreen::TotaleBalane:
		{
			_ShowTotaleBalane();
			_GetBackToTransactionMenu();
			break;
		};
		case clsShowTransactionScreen::TransferScreen:
		{
			_ShowTransferScreen();
			_GetBackToTransactionMenu();
			break;
		};
		case clsShowTransactionScreen::TransferLog:
		{
			_ShowtransfersLogScreen();
			_GetBackToTransactionMenu();
			break;
		};
		case clsShowTransactionScreen::MainMenu:
		{
			break;
			//_ShowMainMenu();
		};
		}
	}

public:

	static void showTransactionScreen()
	{
		if (!checkAccessRights(clsBankUser::enUserPromissions::pTransection))
		{
			system("pause");
			return;//This Function Will Check User Permissions
		}
		system("cls");
		clsScreen::showHeaderMenu("Transaction Screen");
		cout << "\t\t\t\t  Transaction Menu\n";
		cout << setw(40) << "\t\t\t_______________________________________" << endl;
		cout << "\t\t\t [1] Deposite Clint \n";
		cout << "\t\t\t [2] With Draw \n";
		cout << "\t\t\t [3] Totale Balance \n";
		cout << "\t\t\t [4] Transfers \n";
		cout << "\t\t\t [5] Transfer Log Screen \n";
		cout << "\t\t\t [6] Main Menue \n";
		cout << setw(40) << "\t\t\t_______________________________________" << endl;

		_PerformChoies((enTransactionCoies)_readOptionNumber());
	}


};

