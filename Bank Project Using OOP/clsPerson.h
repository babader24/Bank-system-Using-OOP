#pragma once
#include <iostream>

using namespace std; 


class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;	

public:
	clsPerson(string firstName, string lastName, string email, string phone)
	{
		_FirstName = firstName;
		_LastName = lastName;
		_Email = email;
		_Phone = phone;
	}
	void setFirstName(string firstName)
	{
		_FirstName = firstName;
	}
	string GetfirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetfirstName, put = setFirstName))string firstName;
	void setLastName(string lastName)
	{
		_LastName = lastName;
	}
	string GetlastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetlastName, put = setLastName))string lastName;
	void setEmail(string email)
	{
		_Email = email;
	}
	string Getemail()
	{
		return _Email;
	}
	__declspec(property(get = Getemail, put = setEmail))string email;
	void setPhone(string phone)
	{
		_Phone = phone;
	}
	string Getphone()
	{
		return _Phone;
	}
	__declspec(property(get = Getphone, put = setPhone))string phone;
	string fullName()
	{
		return _FirstName + "" + _LastName;
	}

};

