#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUlit.h"
class clsTotalBalences:clsScreen
{
private:
	static void _printRecordTotalBelance(clsBankClient Client) {
		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(40) << left << Client.fullName();
		cout << "| " << setw(12) << left << to_string(Client.Belence);
		cout << endl;
	}

public:
	static void ShowTotalBalence() {
		vector<clsBankClient> Vclient;
		Vclient = clsBankClient::GetClients();

		clsScreen::_drowHeaderScreen("Total Balence Screen");

		cout << "\n\t\t\t\t\t Clients Is (" << Vclient.size() << ") (s)\n";
		cout << "_______________________________________________________________________";
		cout << "________________________________\n";

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Account Balence";
		cout << "\n_______________________________________________________________________";
		cout << "________________________________\n";

		if (Vclient.size() == 0) {
			cout << "\n\t\t\t\t The date of clients is not found ....:( \n";
		}
		else {
			for (clsBankClient& C : Vclient) {
				_printRecordTotalBelance(C);
			}
		}
		cout << "_______________________________________________________________________";
		cout << "________________________________\n";
		int TotalBelance = clsBankClient::GetTotalBelance();
		cout << "\n\t\t\t\t Total Belance Is = $" << TotalBelance << endl;
		cout << "\t\t\t\t (" << clsUlit::NumberToText(TotalBelance) << " Dolar)\n";
	}

};

