#pragma once
#include "clsScreen.h";
#include "clsCurrency.h";
#include "clsInputVaildation.h";

class clsUpdateCurrencyScreen :protected clsScreen
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

	static bool _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
			return true;
		}
		else
		{
			cout << "\nCurrency Not Found \n";
			return false;
		}
	}

public:

	static void showUpdateCurrencyScreen()
	{
		clsScreen::showHeaderMenu("Delete Clint");

		cout << "Please Enter Currency Code: ";
		string currencyCode = clsValidation::readString();

		clsCurrency currency = currency.FindByCurrency(currencyCode);

		if (_ShowResult(currency))
		{
			float answer;
			cout << "\nDo You Want To Update This Currency Rate? y/N";
			if (clsValidation::readYesOrNo())
			{
				cout << "\nEnter The New Rate: ";

				cin >> answer;
				currency.UpdateRate(answer);
				cout << "The Currency Rate Upadte Successfully :-)\n";
				_PrintCurrency(currency);
			}
			else
			{
				cout << "The Opration Just Canclled!\n";
			}
		}
	}
};

