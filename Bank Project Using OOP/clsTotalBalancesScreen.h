#pragma once
#include "clsScreen.h";
#include "clsBankClint.h";
#include "clsUtil.h";

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private:

	static void printClintBalance(clsBankClint clint)
	{
		cout << "|" << left << setw(15) << clint.acountNumber();
		cout << "|" << left << setw(15) << clint.fullName();
		cout << "|" << left << setw(15) << clint.AcountBalance << endl;
	}

public:

	static void showTotalBalances()
	{
		vector <clsBankClint> vClint = clsBankClint::GetClintsRecord();
		string title = "Total Balances";
		string subTitle = "(" + to_string(vClint.size()) + ") clint's";

		clsScreen::showHeaderMenu(title, subTitle);
		cout << setw(45) << "_______________________________________________\n";
		cout << "        Total Balances[" << vClint.size() << "] clint's\n";
		cout << setw(45) << "_______________________________________________\n";
		cout << "|" << left << setw(15) << "AcountNumber";
		cout << "|" << left << setw(15) << "FullName";
		cout << "|" << left << setw(15) << "AcountPalance" << endl;
		cout << setw(45) << "_______________________________________________\n";

		double total = clsBankClint::GetTotalBalances();
		if (vClint.size() == 0)
		{
			cout << "\t\t\tNo Clint Avalibale.\n";
		}
		for (clsBankClint& c : vClint)
		{
			printClintBalance(c);

		}
		cout << setw(45) << "_______________________________________________\n";


		cout << "Total Balances = " << total << endl;
		cout << clsUtil::NumberToText( total) << endl;
	}
};

