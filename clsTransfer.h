#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
class clsTransfer:protected clsScreen
{
private:
	static void _printInfoOfclient(clsBankClient client) {
		cout << " \bClient Card\n";
		cout << "_____________________________________\n";
		cout << "Name client     : " << client.fullName() << endl;
		cout << "Account Number  : " << client.GetAccountNumber() << endl;
		cout << "Account Balence : " << client.Belence << endl;
		cout << "_____________________________________\n\n";
	}
	 static string _ReadAmount() {
		string AccN1 = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccN1)) {
			cout << "Plases Check your Account Number is Valide !!";
			AccN1 = clsInputValidate::ReadString();
		}
		return AccN1;
	}
	static  int _ReadAmount(clsBankClient sourceClient) {
		 cout << "Enter Amount transfer ";
		 int Amount = clsInputValidate::ReadIntNumber();
		 while (Amount > sourceClient.Belence)
		 {
			 cout << "Error ! The input Amount is GeatThan your Balence , please Try Agian ->  ";
			 Amount = clsInputValidate::ReadIntNumber();
		 }
		 return Amount;
	 }
public:
	static void TreansferSceen() {
		clsScreen::_drowHeaderScreen("Transfer Screen");
		cout << "\nEnter Account Number to Trensfer From : ";
		clsBankClient client1 = clsBankClient::Find(_ReadAmount());
		_printInfoOfclient(client1);


		cout << "\nEnter Account Number to Trensfer To : ";
		
		clsBankClient client2 = clsBankClient::Find(_ReadAmount());
		_printInfoOfclient(client2);

	//+++++++++++++++++++++++
		int Amount = _ReadAmount(client1);
		char ans;
		cout << "Are you sure do you perferm opration (y - N) ";
		cin >> ans;
		if (toupper(ans) == 'Y') {

			if (client1.transfer(Amount,client2)) {

			cout << "\nthe transfer Is suceessfully :-) \n";
		}


		}
		else {
			cout << "\n Okay go bakc ...-> \n";
		}
		
	}
};

