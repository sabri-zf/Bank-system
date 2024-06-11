#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"

class clsUpdateClient:clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& client) {
		client.GetAccountNumber();

		cout << "Enter first Name  ? ";
		client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter last Name ? ";
		client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Phone     ? ";
		client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Email     ? ";
		client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Pin Code  ? ";
		client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Account Belance ? ";
		client.Belence = clsInputValidate::ReadIntNumber();
	}

public:
	static void UpdateClientInfo() {
		if (!checkpermisonRight(clsUser::eShowUpdate)) {
			return;
		}
		clsScreen::_drowHeaderScreen("Update Client Screen");
		cout << "Please Enter Account Number ? ";

		string AccountNumber = clsInputValidate::ReadString();

		while ((clsBankClient::IsClientExist(AccountNumber))) {
			cout << "The Account Number is not valide , please Enter another : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient client = clsBankClient::Find(AccountNumber);
		clsScreen::_printInfo(client);

		_ReadClientInfo(client);

		char ans;
		cout << "\n\nAre you sure , do you want Update client ? ";
		cin >> ans;

		if (toupper(ans) == 'Y') {
			clsBankClient::enSave Saved;
			Saved = client.Save();

			switch (Saved)
			{
			case clsBankClient::svFailEmotyObject:
				cout << "\nEroor Account was not Save client\n";
				break;
			case clsBankClient::svSuccseefullyObject:
				cout << "\nAccount Upadet Successfully\n";
				clsScreen::_printInfo(client);
				break;
			}

		}
		else {
			cout << "\nOkay , NoThank Do.. !!\n";
		}
	}

};

