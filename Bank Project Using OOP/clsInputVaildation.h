#pragma once
#include <iostream>
#include <string>;
#include "clsDate.h";

using namespace std;


class clsValidation
{
public:

	static bool isNumberBetween(float num, float num1, float num2)
	{
		return num >= num1 || num <= num2;
	}

	static bool isDateBetween(clsDate date, clsDate date1, clsDate date2)
	{
		return date.isDate1BeforeDate2(date2) && date.isDate1AfterDate2(date1);
	}

	static double readDbNumber(string massage = "Invalid, Enter Again \n")
	{
		double num;
		while (!(cin >> num))
		{
			
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << massage;
		}
		return num;
	}

	static int readIntNumber(string massage = "Invalid, Enter Again \n")
	{
		int num;

		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << massage;
		}
		return num;
	}

	static float readFloatNumber(string massage = "Invalid, Enter Again \n")
	{
		float num;

		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << massage;
		}
		return num;
	}

	static bool isValidDate(clsDate date)
	{
		return clsDate::isValidateDate(date);
	}

	static string readString()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}

	static bool readAnswer()
	{
		string massage;
		cout << "\nAre You Sure? y/Y ";
		char answer;
		cin >> answer;
		return toupper(answer) == 'Y';
	}

	static bool readAnswerWithMassage(string massage ="\nAre You Sure? y/Y " )
	{
		char answer;
		cout << massage;
		cin >> answer;
		return toupper(answer) == 'Y';
	}

	static short readShortNumberBetween(int from, int to)
	{
		short num;
		cout << "Enter a Number from " << from << " To " << to << " : ";
		cin >> num;
		while ((num<from || num>to) && !(cin >> num))
		{
			//cout << "Invalid NUmber, please Enter a Number from " << from << " To " << to << " : ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid NUmber, please Enter a Number from " << from << " To " << to << " : ";
			cin >> num;
		}
		return num;
	}

	static double readPositiveNumber()
	{
		double num;
		cin >> num;	

		while (num <= 0)
		{
			cout << "Error, Please Enter a Positive Number : ";
			cin >> num;
		}
		return num;
	}

	static bool readYesOrNo(string massage = "\n Invalid, Please Enter [y or n]: ")
	{
		char answer = ' ';
		cout << "\nAre You Sure? Answer Whith Only y/n";
		cin >> answer;

		while (toupper(answer) != 'Y' && toupper(answer) != 'N')
		{
			cout << massage;
			cin >> answer;
		}
		return toupper(answer) == 'Y';
	}

};
