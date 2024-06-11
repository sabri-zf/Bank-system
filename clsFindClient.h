#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"

class clsFindClient:clsScreen
{
public:
	static void FindClient() {
		if (!checkpermisonRight(clsUser::eShowFind)) {
			return;
		}
		clsScreen::_drowHeaderScreen("Find Clinet Screen ");
		cout << "Enter Your Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "The Account Number is not Found, Shooes Another Value : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		clsScreen::_printInfo(Client1);
	}

};

