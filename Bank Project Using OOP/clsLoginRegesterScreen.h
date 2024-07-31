#pragma once
#include "clsScreen.h";
#include "clsBankUser.h";
using namespace std;
class clsLoginRegesterScreen : protected clsScreen
{
private:
	static void printClintBalance(clsBankUser::stLoginRecord clint)
	{
		cout << "\t\t|" << left << setw(30) << clint.dateTime;
		cout << "|" << left << setw(15) << clint.userName;
		cout << "|" << left << setw(8) << clint.password;
		cout << "|" << left << setw(8) << clint.permisson << endl;
	}
public:
	static void showRegesterScreen()
	{
		if (!checkAccessRights(clsBankUser::enUserPromissions::pShowClintList))
		{
			return;//This Function Will Check User Permissions
		}

		vector <clsBankUser::stLoginRecord> vLoginRecord = clsBankUser::GetloginRegesterList();
		string title = " Login Regeater List ";
		string subTitle = "(" + to_string(vLoginRecord.size()) + ") Records";

		clsScreen::showHeaderMenu(title, subTitle);
		cout << setw(45) << "\t\t______________________________________________________________________\n";
		cout << "\t\t|" << left << setw(30) << "Date ";
		cout << "|" << left << setw(15) << "User Name";
		cout << "|" << left << setw(8) << "Password";
		cout << "|" << left << setw(8) << "Permissons" << endl;
		cout << setw(45) << "\t\t______________________________________________________________________\n";

		if (vLoginRecord.size() == 0)
		{
			cout << "\t\t\tNo Clint Avalibale.\n";
		}
		for (clsBankUser::stLoginRecord& Record : vLoginRecord)
		{
			printClintBalance(Record);

		}
		cout << setw(45) << "\t\t______________________________________________________________________\n";
	}
};

