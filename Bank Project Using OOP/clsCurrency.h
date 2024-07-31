#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h";
#include <string>

using namespace std;

class clsCurrency
{
private:
	enum enMode { emptyMode = 0, updateMode = 1 };
	enMode _Mode;
	string _Country;
	string _Currency;
	string _CurrencyName;
	float _Rate;

	static string _ConvertCurrencyToLine(clsCurrency currency, string sep = "#//#")
	{
		string name = "";
		name += currency._Country + sep;
		name += currency._Currency + sep;
		name += currency._CurrencyName + sep;
		name += to_string(currency._Rate);

		return name;
	}

	static clsCurrency _ConvertLineToCurrency(string line, string sep = "#//#")
	{
		vector <string> vCurrency = clsString::Split(line, sep);

		return clsCurrency(enMode::updateMode, vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));
	}

	static vector <clsCurrency> _LoadCurrencyFile()
	{
		vector<clsCurrency> vCurrency;
		fstream File;
		File.open("Currencies.txt", ios::in);//read Only

		if (File.is_open())
		{
			string line;
			while (getline(File, line))
			{
				clsCurrency currency = _ConvertLineToCurrency(line);
				vCurrency.push_back(currency);
			}
			File.close();
		}
		return vCurrency;
	}

	static void _Save(vector <clsCurrency> vCurrency)
	{
		fstream File;
		File.open("Currencies.txt", ios::out);

		if (File.is_open())
		{
			string line;
			for (clsCurrency& C : vCurrency)
			{
				line = _ConvertCurrencyToLine(C);
				File << line << endl;
			}
			File.close();
		}


	}

	void _Update()
	{
		vector<clsCurrency> vCurrency = _LoadCurrencyFile();

		for (clsCurrency& C : vCurrency)
		{
			if (C._Currency == Currency())
			{
				C = *this;
			}
		}
		_Save(vCurrency);
	}

	static clsCurrency _GetEmptyCurrency()
	{
		return clsCurrency(enMode::emptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode mode, string country, string currency, string currencyName, float rate)
	{
		_Mode = mode;
		_Country = country;
		_Currency = currency;
		_CurrencyName = currencyName;
		_Rate = rate;
	}

	static vector <clsCurrency> GetAllUSDRates() 
	{
		return _LoadCurrencyFile();
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::emptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string Currency()
	{
		return _Currency;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float num)
	{
		_Rate = num;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}
	//__declspec(property(get = Rate, put = SetRate))float rate;

	static clsCurrency FindByCurrency(string currency)
	{
		vector<clsCurrency>vCurrency = _LoadCurrencyFile();

		for (clsCurrency& C : vCurrency)
		{
			if (clsString::UpperAllString(C.Currency()) == clsString::UpperAllString(currency))
			{
				return C;
			}
		}
		return _GetEmptyCurrency();
	}

	static clsCurrency FindByCountry(string country)
	{
		vector<clsCurrency>vCurrency = _LoadCurrencyFile();

		for (clsCurrency& C : vCurrency)
		{
			if (clsString::UpperAllString(C.Country()) == clsString::UpperAllString(country))
			{
				return C;
			}
		}
		return _GetEmptyCurrency();
	}

	static bool IsCurrencyExist(string currency)
	{
		clsCurrency Currency = FindByCurrency(currency);
		return Currency.IsEmpty();
	}

};

