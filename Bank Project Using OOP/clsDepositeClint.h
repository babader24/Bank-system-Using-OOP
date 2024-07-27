#pragma once
#include "clsScreen.h";
#include "clsBankClint.h";
using namespace std; 

class clsDepositeClint : protected clsScreen
{
private:
	static void _PrintClint(clsBankClint clint)
	{
		cout << "\n=================\n";
		cout << "   Clint Card\n";
		cout << "\n=================\n";
		cout << "First Name : " << clint.firstName << endl;
		cout << "Last Name  : " << clint.lastName << endl;
		cout << "Full Name  : " << clint.fullName() << endl;
		cout << "Email      : " << clint.email << endl;
		cout << "Phone      : " << clint.phone << endl;
		cout << "Acc.Number : " << clint.acountNumber() << endl;
		cout << "Password   : " << clint.pincode << endl;
		cout << "Balance    : " << clint.AcountBalance << endl;
		cout << "_______________________________\n";
	}

	static string _ReadAccountNumber()
	{
		cout << "Please Enter Account Number : ";
		string AccountNumber = clsValidation::readString();
		return AccountNumber;
	}

public:
	static void deposteClint()
	{
		clsScreen::showHeaderMenu("Deposite Screen");
		string accountNumber = _ReadAccountNumber();

		while (!clsBankClint::isClintExist(accountNumber))
		{
			cout << "Clint Not Found, Please Enter a Valid One: ";
			accountNumber = clsValidation::readString();
		}
		clsBankClint clint = clsBankClint::Find(accountNumber);
		_PrintClint(clint);

		double ammount = 0;

		cout<< "\nPlease Enter a Deposite : ";
		ammount = clsValidation::readPositiveNumber();

		char answer = 'n';
	
		if (clsValidation::readAnswerWithMassage("Are You Sure You Want To Perform This Deposite? "))
		{
			clint.deposite(ammount);
			cout << "\nDeposite Complete Successfully :-)\n";
			cout << "The New Balanc Is: " << clint.AcountBalance << endl;
		}
		else
		{
			cout << "Error, Oparations Was Cancelled ";
		}
		
	}
};

