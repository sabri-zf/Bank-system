#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"

class clsDeleteClient:clsScreen
{
public:
	static void DeleteClient() {
		if (!checkpermisonRight(clsUser::eShowDelete)) {
			return;
		}
		clsScreen::_drowHeaderScreen("Delete Clinet Screen ");
		cout << "Enter Your Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "The Account Number is not Found, Shooes Another Value : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		clsScreen::_printInfo(Client1);
		char ans;
		cout << "\n Are you sure , Do You want Delete client ? ";
		cin >> ans;
		if (toupper(ans) == 'Y') {

			if (Client1.Delete()) {
				cout << "Delet Client Is Succseefully :) \n";
			}
			else {
				cout << "Error Delet Client Is Not Succseefully :( \n";
			}

		}
		else {
			cout << "\nNot Do any think :) \n";
		}
	}

};

