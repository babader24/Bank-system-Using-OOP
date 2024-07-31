#pragma once
#include "clsScreen.h";

class clsTransferLogScreen : protected clsScreen
{
private:
	static void printTransferOps(clsBankClint::stTransferLog transfer)
	{
		cout << "|" << left << setw(20) << transfer.date;
		cout << "|" << left << setw(15) << transfer.senderAccount;
		cout << "|" << left << setw(15) << transfer.reciverAccount;
		cout << "|" << left << setw(8) << transfer.ammount;
		cout << "|" << left << setw(15) << transfer.senderBalance;
		cout << "|" << left << setw(15) << transfer.reciverBalance;
		cout << "|" << left << setw(8) << transfer.user << endl;

	}

public:

	static void showTransferLogScreen()
	{
		vector <clsBankClint::stTransferLog> vTransfers = clsBankClint::GetTransferLogList();
		string title = " Login Regeater List ";
		string subTitle = "(" + to_string(vTransfers.size()) + ") Records";

		clsScreen::showHeaderMenu(title, subTitle);
		cout << setw(45) << "__________________________________________________________________________________________________________\n";
		cout << "|" << left << setw(20) << "Date ";
		cout << "|" << left << setw(15) << "Sender Account";
		cout << "|" << left << setw(15) << "Reciver Account";
		cout << "|" << left << setw(8) << "Ammount";
		cout << "|" << left << setw(15) << "Sender Balance";
		cout << "|" << left << setw(15) << "Receiver balance";
		cout << "|" << left << setw(8) << "User Name" << endl;
		cout << setw(45) << "\__________________________________________________________________________________________________________\n";

		if (vTransfers.size() == 0)
		{
			cout << "\t\t\tNo Clint Avalibale.\n";
		}
		for (clsBankClint::stTransferLog& transfer : vTransfers)
		{
			printTransferOps(transfer);

		}
		cout << setw(45) << "__________________________________________________________________________________________________________\n";
	}
};

