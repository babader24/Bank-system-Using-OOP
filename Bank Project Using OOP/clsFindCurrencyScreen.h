#pragma once
#include "clsScreen.h";
#include "clsCurrency.h";
#include"clsInputVaildation.h";

class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
{
    cout << "\nCurrency Card:\n";
    cout << "_____________________________\n";
    cout << "\nCountry    : " << Currency.Country();
    cout << "\nCode       : " << Currency.Currency();
    cout << "\nName       : " << Currency.CurrencyName();
    cout << "\nRate(1$) = : " << Currency.Rate();

    cout << "\n_____________________________\n";

}

    static void _ShowResult(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout<<"\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Not Found \n";
        }
    }
public:

	static void showFindCurrencyScreen()
	{
		clsScreen::showHeaderMenu("Find Currency");

        cout << "\nTo Find Currency By Code Press[1], Or By Country Name Press[2]:\n ";
        short answer = clsValidation::readShortNumberBetween(1, 2);
        string currency;
        if (answer == 1)
        {
            cout << "Enter Currency Code:  ";
            currency = clsValidation::readString();
            clsCurrency C = clsCurrency::FindByCurrency(currency);
            _ShowResult(C);
        }
        else if (answer == 2)
        {
            cout << "Enter Country Name:  ";
            currency = clsValidation::readString();
            clsCurrency C = clsCurrency::FindByCountry(currency);
            _ShowResult(C);

        }
        
	}
};

