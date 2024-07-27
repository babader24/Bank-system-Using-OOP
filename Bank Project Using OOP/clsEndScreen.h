#pragma once
#include "clsScreen.h";

class clsEndScreen:protected clsScreen
{
public:
	static void showEndScreen()
	{
		clsScreen::showHeaderMenu("   End Screen");

		cout << "\t\t\t\t\t\GOOD BYE\n";
		cout << setw(40) << "\t\t\t_______________________________________\n\n\n" << endl;

		system("pause");
	}
};

