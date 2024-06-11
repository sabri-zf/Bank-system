#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"

class clsAddNewClient:protected clsScreen
{
private:
	static  void _ReadAddclient(clsBankClient& NewClient) {
		cout << "\n Enter First Name : ";
		NewClient.FirstName = clsInputValidate::ReadString();
		cout << "\n Enter Last Name : ";
		NewClient.LastName = clsInputValidate::ReadString();
		cout << "\n Enter Phone : ";
		NewClient.Phone = clsInputValidate::ReadString();
		cout << "\n Enter Email : ";
		NewClient.Email = clsInputValidate::ReadString();
		cout << "\n Enter Code Pin : ";
		NewClient.PinCode = clsInputValidate::ReadString();
		cout << "\n Enter Account Belance : ";
		NewClient.Belence = clsInputValidate::ReadIntNumber();
	}


public:
	static void AddNewClient() {
		if (!checkpermisonRight(clsUser::eShowAddNew)) {
			return;
		}
		clsScreen::_drowHeaderScreen("Add New Client");
		cout << "Enter Account Number : ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!(clsBankClient::IsClientExist(AccountNumber))) {
			cout << "This Client Of ["<<AccountNumber<<"] On System!! ,Please Enter Another Account Number : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		cout << "\n=================================\n";
		cout << "          Append Client";
		cout << "\n=================================\n";

		clsBankClient AddClient = clsBankClient::GetAddClient(AccountNumber);

		_ReadAddclient(AddClient);

		clsBankClient::enSave ResultSave;

		ResultSave = AddClient.Save();

		switch (ResultSave)
		{
		case clsBankClient::svFailEmotyObject:
			cout << "\nEroor Account was not Save client\n";
			break;
		case clsBankClient::svSuccseefullyObject:

			cout << "\nAccount Upadet Successfully\n\n";
			clsScreen::_printInfo(AddClient);
			

			break;
		}

	}

};

