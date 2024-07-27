#pragma once
#include <iostream>
#include <iomanip>
#include "clsPerson.h";
#include "clsString.h";
#include <string>
#include <fstream>

using namespace std;
class clsBankClint : public clsPerson
{
private:
	enum enMode{EmptyMode = 0, UpdateMpde = 1,AddnewMode = 2};
	enMode _Mode;
	string _AcountNumber;
	string _Pincode;
	float _AcountBalance;
	bool _MarkedForDelete = false;

	static clsBankClint _convertLineToClintObject(string line, string separator = "#//#")
	{
		vector<string> vClint;
		vClint = clsString::Split(line, separator);
		//Ahmed#//#Babader#//#ahmedbabader7@gmail.com#//#7388830#//#A123#//#1234#//#9000#//#
		return clsBankClint(enMode::UpdateMpde, vClint[0], vClint[1], vClint[2], vClint[3], vClint[4], vClint[5], stof(vClint[6]));
	}

	static string _convertClintObjectToLine(clsBankClint clint, string separator = "#//#")
	{
		string name = "";
		name += clint.firstName + separator;
		name += clint.lastName + separator;
		name += clint.email + separator;
		name += clint.phone + separator;
		name += clint._AcountNumber + separator;
		name += clint.pincode + separator;
		name += to_string(clint.AcountBalance) + separator;

		return name;
	}

	static vector <clsBankClint> _LoadDataFromFile()
	{
		vector<clsBankClint>vClint;
		
		fstream file;
		file.open("Clint.txt", ios::in);

		if (file.is_open())
		{
			string line = "";

			while (getline(file, line))
			{
				clsBankClint clint = _convertLineToClintObject(line);
				vClint.push_back(clint);
			}
			file.close();
		}
		return vClint;
	}

	static void _SaveClintDataToFile(vector <clsBankClint> vClint)
	{
		fstream file;
		file.open("Clint.txt", ios::out);

		if (file.is_open())
		{
			string line;
			for (clsBankClint& C : vClint)
			{
				if(C.MarkedForDelete() == false)
				{
					line = _convertClintObjectToLine(C);
					file << line << endl;
				}
			}
			file.close();
		}
	}

	void _Update()
	{
		vector <clsBankClint> vClint;
		vClint = _LoadDataFromFile();

		for (clsBankClint& C : vClint)
		{
			if (C.acountNumber() == acountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClintDataToFile(vClint);
	}

	void  _AddNew()
	{
		_AddDataLineToFile(_convertClintObjectToLine(*this));
	}
	
	void _AddDataLineToFile(string line)
	{
		fstream file;

		file.open("Clint.txt", ios::out | ios::app);

		if (file.is_open())
		{
			file << line << endl;
			file.close();
		}

	}

	static clsBankClint _GetEmptyObject()
	{
		return clsBankClint(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	clsBankClint(enMode mode, string firstName, string lastName, string email, string phone, string acountNumber, string pincode, float acountBalance)
		: clsPerson(firstName, lastName, email, phone)
	{
		_Mode = mode;
		_AcountNumber = acountNumber;
		_Pincode = pincode;
		_AcountBalance = acountBalance;
	}

	string acountNumber()
	{
		return _AcountNumber;
	}

	void setPincode(string pincode)
	{
		_Pincode = pincode;
	}

	string getPincode()
	{
		return _Pincode;
	}

	__declspec(property(get = getPincode, put = setPincode))string pincode;

	void setAcountBalance(float AcountBalance)
	{
		_AcountBalance = AcountBalance;
	}

	float getAcountBalance()
	{
		return _AcountBalance;
	}

	__declspec(property(get = getAcountBalance, put = setAcountBalance))float AcountBalance;

	void setMarkedForDelete(bool M)
	{
		_MarkedForDelete = M;
	}
	
	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	__declspec(property(get = MarkedForDelete, put = setMarkedForDelete))bool Mark;

	bool isEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	//Ui Not Related To ObJ
	/*void print()
	{
		cout << "\n=================\n";
		cout << "   Clint Card\n";
		cout << "\n=================\n";
		cout << "First Name : " << firstName<<endl;
		cout << "Last Name  : " << lastName << endl;
		cout << "Full Name  : " << fullName() << endl;
		cout << "Email      : " << email << endl;
		cout << "Phone      : " << phone << endl;
		cout << "Acc.Number : " << _AcountNumber << endl;
		cout << "Password   : " <<_Pincode << endl;
		cout << "Balance    : " << _AcountBalance << endl;
		cout << "_______________________________\n";

	}*/

	static clsBankClint Find(string accountNumber)
	{
		fstream file;
		file.open("Clint.txt", ios::in);//read Only

		if (file.is_open())
		{
			vector<clsBankClint> vClint;
			string line;
			while (getline(file, line))
			{
				clsBankClint clint = _convertLineToClintObject(line);
				if (clint._AcountNumber == accountNumber)
				{
					file.close();
					return clint;
				}
				vClint.push_back(clint);
			}
			file.close();
		}
		return _GetEmptyObject();
	}

	static clsBankClint Find(string accountNumber, string pincode)
	{
		fstream file;
		file.open("Ahmed.txt", ios::in);//read Only

		if (file.is_open())
		{
			vector<clsBankClint> vClint;
			string line;
			while (getline(cin, line))
			{
				clsBankClint clint = _convertLineToClintObject(line);
				if (clint._AcountNumber == accountNumber && clint._Pincode == pincode)
				{
					file.close();
					return clint;
				}
				vClint.push_back(clint);
			}
			file.close();
		}
		return _GetEmptyObject();
	}

	static bool isClintExist(string accountNumber)
	{
		clsBankClint clint = clsBankClint::Find(accountNumber);
		return (!clint.isEmpty());
	}

	enum enSaveResult {svFaildEmptyObject = 0, svSuccessed = 1, svFaileAccountExist};

	enSaveResult save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if(isEmpty())
			{
				return enSaveResult::svFaildEmptyObject;
			}
		}
		case enMode::UpdateMpde:
		{
			_Update();
			return enSaveResult::svSuccessed;
		}
		case enMode::AddnewMode:
		{
			if (clsBankClint::isClintExist(_AcountNumber))
			{
				return enSaveResult::svFaileAccountExist;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMpde;
				return enSaveResult::svSuccessed;
			}
		}
		}
	}

	static clsBankClint addNewClint(string accountNumber)
	{
		return clsBankClint(enMode::AddnewMode, "", "", "", "", accountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClint> vClint = _LoadDataFromFile();
		for (clsBankClint& C : vClint)
		{
			if (C.acountNumber() == _AcountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}
		_SaveClintDataToFile(vClint);

		*this = _GetEmptyObject();
		return true;
	}

	static vector<clsBankClint> GetClintsRecord()
	{
		return _LoadDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClint> vClint = clsBankClint::GetClintsRecord();
		double totalBalances = 0;

		for (clsBankClint& C : vClint)
		{
			totalBalances += C.AcountBalance;
		}
		return totalBalances;
	}

	void deposite(double num)
	{
		_AcountBalance += num;
		save();
	}

	bool withDraw(double num)
	{
		if (_AcountBalance < num)
		{
			return false;
		}
		else
		{
			_AcountBalance -= num;
			save();
			return true;
		}
	}
};

