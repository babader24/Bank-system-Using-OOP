#pragma once
#include "clsBankClint.h";
#include "clsScreen.h";
#include <iostream>
#include <iomanip>

using namespace std;

class clsClintList :protected clsScreen
{
private:
	static void printClint(clsBankClint clint)
	{
		cout << "|" << left << setw(15) << clint.acountNumber();
		cout << "|" << left << setw(15) << clint.fullName();
		cout << "|" << left << setw(25) << clint.email;
		cout << "|" << left << setw(10) << clint.phone;
		cout << "|" << left << setw(15) << clint.pincode;
		cout << "|" << left << setw(15) << clint.AcountBalance << endl;
	}

public:

	static void showClintsList()
	{
		if (!checkAccessRights(clsBankUser::enUserPromissions::pShowClintList))
		{
			return;//This Function Will Check User Permissions
		}

		vector <clsBankClint> vClint = clsBankClint::GetClintsRecord();
		string title = "Clint Screen";
		string subTitle = "(" + to_string(vClint.size()) + ") clint's";

		clsScreen::showHeaderMenu(title, subTitle);

		cout << setw(70) << "_______________________________________________________________________________________________________\n";
		cout << "                                Clint List\n";
		cout << setw(70) << "_______________________________________________________________________________________________________\n";
		cout << "|" << left << setw(15) << "AcountNumber";
		cout << "|" << left << setw(15) << "FullName";
		cout << "|" << left << setw(25) << "Email";
		cout << "|" << left << setw(10) << "PhoneNumber";
		cout << "|" << left << setw(15) << "PinCode";
		cout << "|" << left << setw(15) << "AcountPalance" << endl;
		cout << setw(70) << "_______________________________________________________________________________________________________\n";

		if (vClint.size() == 0)
		{
			cout << "\t\t\tNo Clint Avalibale.\n";
		}
		for (clsBankClint& c : vClint)
		{
			printClint(c);
		}
		cout << setw(70) << "_______________________________________________________________________________________________________\n";
	}

};

