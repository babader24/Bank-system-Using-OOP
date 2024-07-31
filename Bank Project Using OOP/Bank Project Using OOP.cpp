#include <iostream>
#include "clsBankClint.h";
#include "clsInputVaildation.h";
#include "clsUtil.h";
//#include "clsShowScreens.h";
#include "clsLoginScreen.h";
#include "clsCurrency.h";

using namespace std; 

int main()
{
	//clsShowScreens::showMainMenu();
	while (true)
	{
		if (!clsLoginScreen::showLoginScreen())
		{
			break;
		}
	}
}
//static void _PrintCurrency(clsCurrency Currency)
//{
//    cout << "\nCurrency Card:\n";
//    cout << "_____________________________\n";
//    cout << "\nCountry    : " << Currency.Country();
//    cout << "\nCode       : " << Currency.Currency();
//    cout << "\nName       : " << Currency.CurrencyName();
//    cout << "\nRate(1$) = : " << Currency.Rate();
//
//    cout << "\n_____________________________\n";
//
//}
//int main()
//
//{
//    clsCurrency Currency1 = Currency1.FindByCurrency("jod");
//
//    if (Currency1.IsEmpty())
//    {
//        cout << "\nCurrency Is Not Found!\n";
//    }
//    else
//    {
//        _PrintCurrency(Currency1);
//    }
//
//    clsCurrency Currency2 = Currency2.FindByCountry("Yemen");
//
//    if (Currency2.IsEmpty())
//    {
//        cout << "\nCurrency Is Not Found!\n";
//    }
//    else
//    {
//        _PrintCurrency(Currency2);
//    }
//
//    cout << "Currency1 after updating Rate:\n";
//    Currency1.UpdateRate(0.71);
//    _PrintCurrency(Currency1);
//
//
//    return 0;
//}