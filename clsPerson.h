#pragma once
#include<iostream>
#include<string>
#include"clsString.h"

using namespace std;
class clsPerson
{
private:
	string _firstName;
	string _lastName;
	string _Phone;
	string _email;

public:
	clsPerson(string firstName, string lastName, string phone, string email) {
		_firstName = firstName;
		_lastName = lastName;
		_Phone = phone;
		_email = email;
	}

	void SetFirstName(string firstName) {
		_firstName = firstName;
	}
	string GetFirstName() {
		return _firstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

	void SetLastName(string lastName) {
		_lastName = lastName;
	}
	string GetLastName() {
		return _lastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName))string LastName;

	void SetPhone(string phone) {
		_Phone = phone;
	}
	string GetPhone() {
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;

	void SetEmail(string email) {
		_email = email;
	}
	string GetEmail() {
		return _email;
	}
	__declspec(property(get = GetEmail, put = SetEmail))string Email;

	 string fullName() {
		return _firstName + " " + _lastName;
	}
};

