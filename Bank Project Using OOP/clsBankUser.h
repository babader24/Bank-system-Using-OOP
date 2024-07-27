#pragma once
#include <iostream>
#include  "clsPerson.h";
#include <vector>
#include <fstream>
#include "clsString.h";
#include <string>

using namespace std;
class clsBankUser : public clsPerson
{
private:
	enum enUserMode{EmptyMode = 1, UpdateMode = 2, AddNewMode = 3};
	enUserMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MatkedForDelete = false;
	

	static clsBankUser _ConvertLineToUserData(string line, string separator = "#//#")
	{
		vector<string> vUser = clsString::Split(line, separator);

		return clsBankUser(enUserMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], vUser[5], stoi(vUser[6]));
	}

	static string _ConvertUserDataToLine(clsBankUser user, string separator = "#//#")
	{
		string name = "";
		name += user.firstName + separator;
		name += user.lastName + separator;
		name += user.email + separator;
		name += user.phone + separator;
		name += user.GetUserName() + separator;
		name += user.password + separator;
		name += to_string(user.permissions) + separator;
		return name;
	}

	static vector <clsBankUser> _LoadUserFromFileToVector()
	{
		vector< clsBankUser> vUser;
		fstream file;
		file.open("Users.txt", ios::in);//read Only

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsBankUser user = _ConvertLineToUserData(line);
				vUser.push_back(user);
			}
			file.close();
		}
		return vUser;
	}

	static void _SaveUserDateToFile(vector <clsBankUser> vUser)
	{
		fstream file;
		file.open("Users.txt", ios::out);

		if (file.is_open())
		{
			string line;
			for (clsBankUser& C : vUser)
			{
				if (C.GetMarkedForDelete() == false)
				{
					line = _ConvertUserDataToLine(C);
					file << line << endl;
				}
			}
			file.close();
		}
	}

	void _UpdateUser()
	{
		vector <clsBankUser> vUser;
		vUser = _LoadUserFromFileToVector();

		for (clsBankUser& C : vUser)
		{
			if (C.GetUserName() == GetUserName())
			{
				C = *this;
				break;
			}
		}
		_SaveUserDateToFile(vUser);
	}

	void  _AddNewUser()
	{
		_AddUserLineToFile(_ConvertUserDataToLine(*this));
	}

	void _AddUserLineToFile(string line)
	{
		fstream file;

		file.open("Users.txt", ios::out | ios::app);

		if (file.is_open())
		{
			file << line << endl;
			file.close();
		}

	}

	static clsBankUser _GetEmptyUserObj()
	{
		return clsBankUser(enUserMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	clsBankUser(enUserMode mode, string firstName, string lastName, string email, string phone, string userName, string password, int permissions)
		:clsPerson(firstName, lastName, email, phone)
	{
		_Mode = mode;
		_UserName = userName;
		_Password = password;
		_Permissions = permissions;

	}

	enum enUserPromissions
	{
		pShowClintList = 1 << 0, pAddNewClint = 1 << 1,
		pDeleteClint = 1 << 2, pUpdateCilnt = 1 << 3,
		pFindClint = 1 << 4, pTransection = 1 << 5,
		pUserMangment = 1 << 6
	};
	bool isEmpty()
	{
		return (_Mode == enUserMode::EmptyMode);
	}

	string GetUserName()
	{
		return _UserName;
	}

	bool GetMarkedForDelete()
	{
		return _MatkedForDelete;
	}

	void SetPassword(string name)
	{
		_Password = name;
	}

	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string password;

	void SetPermissions(int num)
	{
		_Permissions = num;
	}

	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions))int permissions;

	static clsBankUser Find(string username)
	{
		vector<clsBankUser> vUser = _LoadUserFromFileToVector();
		fstream file;
		file.open("Users.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file,line))
			{
				clsBankUser user = _ConvertLineToUserData(line);
				if (user.GetUserName() == username)
				{
					file.close();
					return user;
				}
				vUser.push_back(user);
			}
			file.close();
		}
		return _GetEmptyUserObj();
	}

	static clsBankUser Find(string username, string password)
	{
	vector<clsBankUser> vUser = _LoadUserFromFileToVector();
	fstream file;
	file.open("Users.txt", ios::in);

	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			clsBankUser user = _ConvertLineToUserData(line);
			if (user.GetUserName() == username && user.password == password)
			{
				file.close();
				return user;
			}
			vUser.push_back(user);
		}
		file.close();
	}
	return _GetEmptyUserObj();
	}
	
	enum enSaveResult { svFaildEmptyObject = 0, svSuccessed = 1, svFaileAccountExist };

	static bool isUserExsit(string userName)
	{
		clsBankUser user = Find(userName);
		return (!user.isEmpty());
	}

	enSaveResult SaveUser()
	{
		switch (_Mode)
		{
		case enUserMode::EmptyMode:
		{
			if (isEmpty())
			{
				return enSaveResult::svFaildEmptyObject;
			}
		}
		case enUserMode::UpdateMode:
		{
			_UpdateUser();
			return enSaveResult::svSuccessed;
		}
		case enUserMode::AddNewMode:
		{
			if (clsBankUser::isUserExsit(_UserName))
			{
				return enSaveResult::svFaileAccountExist;
			}
			else
			{
				_AddNewUser();

				_Mode = enUserMode::UpdateMode;
				return enSaveResult::svSuccessed;
			}
		}
		}
	}

	bool DeleteUser()
	{
		vector<clsBankUser> vClint = _LoadUserFromFileToVector();
		for (clsBankUser& C : vClint)
		{
			if (C.GetUserName() == _UserName)
			{
				C._MatkedForDelete = true;
				break;
			}
		}
		_SaveUserDateToFile(vClint);

		*this = _GetEmptyUserObj();
		return true;

	}

	static vector<clsBankUser> getUserRecord()
	{
		return _LoadUserFromFileToVector();
	}
	
	static clsBankUser addNewUser(string userName)
	{
		return clsBankUser(enUserMode::AddNewMode, "", "", "", "", userName,  "", 0);
	}

	bool checkAccessPermissions(enUserPromissions permission)
	{
		if (this->permissions == -1)
			return true;
		if ((permission & this->permissions) == permission)
			return true;
		else
			return false;
	}

};

