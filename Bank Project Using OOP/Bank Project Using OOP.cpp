#include <iostream>
#include "clsBankClint.h";
#include "clsInputVaildation.h";
#include "clsUtil.h";
//#include "clsShowScreens.h";
#include "clsLoginScreen.h";

using namespace std; 

int main()
{
	//clsShowScreens::showMainMenu();
	while(true)
	{
		clsLoginScreen::showLoginScreen();
	}
}
