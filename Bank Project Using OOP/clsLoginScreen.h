#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankUser.h";
#include "Global.h";
#include "clsShowScreens.h";

using namespace std;
class clsLoginScreen : protected clsScreen
{
private:
	static void _Login()
	{
		string userName, password;
		bool loginFaild = false;
		do
		{
			if (loginFaild)
			{
				cout << "Invalid UserName And Password!\n\n";
			}
			cout << "Enter User Name: ";
			cin >> userName;

			cout << "Enter Password: ";
			cin >> password;

			currntUser = clsBankUser::Find(userName, password);
			loginFaild = currntUser.isEmpty();

		} while (loginFaild);
		clsShowScreens::showMainMenu();
	}
public:
	static void showLoginScreen()
	{
		system("cls");
		clsScreen::showHeaderMenu("Login Screen");

		_Login();
	}
};

