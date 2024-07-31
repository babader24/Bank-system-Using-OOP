#pragma once
#include "clsScreen.h";
#include "clsInputVaildation.h";
#include "clsCurrencyListScreen.h";
#include "clsFindCurrencyScreen.h";
#include "clsUpdateCurrencyScreen.h";
#include "clsCalculatorScreen.h";

class clsCurrencyMainScreen : protected clsScreen
{
private:
	enum enCurrncyMeue
	{
		currncyList=1,findCurrency = 2,
		updateRate = 3, currencyCalc = 4,
		mainMenu = 5
	};

	static void _ShowCurrencyList()
	{
		//cout << "Will Be Here Soon";
		clsCurrencyListScreen::showCurrencyList();
	}

	static void _FindCurrency()
	{
		//cout << "Will Be Here Soon";
		clsFindCurrencyScreen::showFindCurrencyScreen();
	}

	static void _UpdateCurrency()
	{
		//cout << "Will Be Here Soon";
		clsUpdateCurrencyScreen::showUpdateCurrencyScreen();
	}

	static void _CurrencyCalc()
	{
		//cout << "Will Be Here Soon";
		clsCalculatorScreen::showCalculatorScreen();
	}

	static void _GetBackToCurrencyMenu()
	{
		cout << "\n To Get Back To Currency Main Menu ";
		system("pause");
		showCurrencyMainScreen();
	}

	static short _readOptionNumber()
	{
		short choise;
		cout << "\t\t\tChoose Number [1-5] :";
		choise = clsValidation::readShortNumberBetween(1, 5);
		return choise;
	}

	static void _PerformChoies(enCurrncyMeue currencyChoies)
	{
		system("cls");
		switch (currencyChoies)
		{
		case clsCurrencyMainScreen::currncyList:
		{
			_ShowCurrencyList();
			_GetBackToCurrencyMenu();
			break;
		}
		case clsCurrencyMainScreen::findCurrency:
		{
			_FindCurrency();
			_GetBackToCurrencyMenu();
			break;
		}
		case clsCurrencyMainScreen::updateRate:
		{
			_UpdateCurrency();
			_GetBackToCurrencyMenu();
			break;
		};
		case clsCurrencyMainScreen::currencyCalc:
		{
			_CurrencyCalc();
			_GetBackToCurrencyMenu();
			break;
		};
		case clsCurrencyMainScreen::mainMenu:
		{
			/*_ShowCurrencyList();
			_GetBackToCurrencyMenu()*/;
			break;
		};
		}
	}

public:

	static void showCurrencyMainScreen()
	{
		//if (!checkAccessRights(clsBankUser::enUserPromissions::pTransection))
		//{
		//	system("pause");
		//	return;//This Function Will Check User Permissions
		//}

		system("cls");
		clsScreen::showHeaderMenu("Currency Main Screen");
		cout << "\t\t\t\t  Currency Menu\n";
		cout << setw(40) << "\t\t\t_______________________________________" << endl;
		cout << "\t\t\t [1] Currency Listt \n";
		cout << "\t\t\t [2] Find Currency \n";
		cout << "\t\t\t [3] Update Rate \n";
		cout << "\t\t\t [4] Currency Calculator \n";
		cout << "\t\t\t [5] Main Menue \n";
		cout << setw(40) << "\t\t\t_______________________________________" << endl;

		_PerformChoies((enCurrncyMeue)_readOptionNumber());
	}
};

