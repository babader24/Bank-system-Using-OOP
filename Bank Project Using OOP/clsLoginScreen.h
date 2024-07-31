#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankUser.h";
#include "Global.h";
#include "clsShowScreens.h";
#include "clsDate.h";

using namespace std;
class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		string userName, password;
		bool loginFaild = false;
		short counter = 3;
		do
		{
			if (loginFaild)
			{
				cout << "\n\nInvalid UserName And Password!";
				counter--;
				if (counter == 0)
				{
					cout << "\n You Are Locked After 3 Fail Trails\n\n";
					return false;
				}
				cout << "\nYou stile Have " << counter << endl<<endl;
			}
			cout << "Enter User Name: ";
			cin >> userName;

			cout << "Enter Password: ";
			cin >> password;

			currntUser = clsBankUser::Find(userName, password);
			loginFaild = currntUser.isEmpty();

		} while (loginFaild);
		currntUser.regesterLogins();
		clsShowScreens::showMainMenu();
	}
public:
	static bool showLoginScreen()
	{
		system("cls");
		clsScreen::showHeaderMenu("Login Screen");

		return _Login();
	}

};

