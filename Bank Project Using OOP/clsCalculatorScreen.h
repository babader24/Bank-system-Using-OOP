#pragma once
#include"clsScreen.h";
#include "clsCurrency.h";

class clsCalculatorScreen : protected clsScreen
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

	static void currencyCalc(clsCurrency& currencyFrom, clsCurrency& currencyTo, float ammount)
	{
		cout << "\nCurrency From: \n";
		_PrintCurrency(currencyFrom);

		float total;
		if (currencyFrom.Currency() != "USD")
		{
			cout << "\n" << ammount << " / " << currencyFrom.Rate() << " = " << ammount / currencyFrom.Rate() << endl;
			total = (ammount / currencyFrom.Rate());
		}
		else
		{
			cout << "\n" << ammount << " * " << currencyFrom.Rate() << " = " << ammount * currencyFrom.Rate() << endl;
			total = (ammount * currencyFrom.Rate());
		}

		if (currencyTo.Currency() != "USD")
		{
			cout << "\nCurrency From USD To: \n";
			_PrintCurrency(currencyTo);
			cout << "\n" << ammount << " * " << currencyTo.Rate() << " = " << total * currencyTo.Rate() << endl;
		}

	}

	static string _ReadCurrency()
	{
		string curr;
		cout << "\nCurrency Code: ";
		cin >> curr;
		while (clsCurrency::IsCurrencyExist(curr))
		{
			cout << "Invalid Currency, Please Enter a Valid Currency Code : ";
			cin >> curr;
		}
		return curr;
	}
public:
	static void showCalculatorScreen()
	{
		system("cls");
		clsScreen::showHeaderMenu("Delete Clint");

		cout << "Enter The Currency You Want To Change From: ";
		string curr1 = _ReadCurrency();
		clsCurrency currencyFrom = currencyFrom.FindByCurrency(curr1);

		cout << "Enter The Currency You Want To Change To: ";
		string curr2 = _ReadCurrency();
		clsCurrency currencyTo = currencyTo.FindByCurrency(curr2);

		float ammount;
		cout << "Pleas Enter the Ammount : ";
		cin >> ammount;

		currencyCalc(currencyFrom, currencyTo, ammount);

		
		cout << "Do You Want To Perform Onther Calculation? y/n:  ";
		char answer;
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			showCalculatorScreen();
		}
	}
};

