#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>

using namespace std;
class clsListClients:protected clsScreen
{
private:
	static void _printInfoOfClient(clsBankClient Client) {
		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(20) << left << Client.fullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << to_string(Client.Belence);
		cout << endl;
	}

public:
	static void ShowclientList() {

		if (!checkpermisonRight(clsUser::eShowList)) {
			return;
		}

		vector<clsBankClient> Vclient;
		Vclient = clsBankClient::GetClients();
		string Tital = "client List";
		string SubTital = "(" + to_string(Vclient.size()) + ")" + "Clientes";

		clsScreen::_drowHeaderScreen(Tital, SubTital);
		cout <<setw(8)<<left<<"" << "_______________________________________________________________________";
		cout << "________________________________\n";

		cout <<setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Account Balence\n";
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n\n";

		if (Vclient.size() == 0) {
			cout << "\n\t\t\t\t The date of clients is not found ....:( \n";
		}
		else {
			for (clsBankClient& C : Vclient) {
				cout << setw(8) << left << "";
				_printInfoOfClient(C);
			}
		}
		cout << setw(8) << left << ""<< "_______________________________________________________________________";
		cout << "________________________________\n";
	}

};

