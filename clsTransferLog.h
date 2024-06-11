#pragma once
#include<iostream>
#include"clsScreen.h"

class clsTransferLog:protected clsScreen
{
private:
	string _DateTime, _SuceBal, _DecsBal, _Amount, _surceAmount, _DecsAmount, _Username;

	static void _printInfoOfClient(clsTransferLog Client) {

		cout << "| " << setw(15) << left << Client._DateTime;
		cout << "| " << setw(8) << left << Client._SuceBal;
		cout << "| " << setw(8) << left << Client._DecsBal;
		cout << "| " << setw(8) << left << Client._Amount;
		cout << "| " << setw(8) << left << Client._surceAmount;
		cout << "| " << setw(8) << left << Client._DecsAmount;
		cout << "| " << setw(8) << left << Client._Username;
		
		cout << endl;
	}


	static clsTransferLog _convertUserHistoryToObject(string line, string spreter = "#//#") {
		vector<string> Vstr;
		Vstr = clsString::splitString(line, spreter);

		return clsTransferLog(Vstr[0], Vstr[1], Vstr[2], Vstr[3], Vstr[4], Vstr[5], Vstr[6]);
	}
	static vector<clsTransferLog> _loadLOginRegister() {
		fstream LoadData;
		vector<clsTransferLog> VresgLoad;
		LoadData.open("trensferLogin.txt", ios::in);
		if (LoadData.is_open()) {
			string line = "";
			while (getline(LoadData, line)) {
				if (line != "") {

					clsTransferLog User = _convertUserHistoryToObject(line);

					VresgLoad.push_back(User);
				}
			}
			LoadData.close();
		}
		return VresgLoad;
	}

	clsTransferLog(string Datime, string surceTrans, string DecrsTrans, string Amount, string surceAmount, string DecrsAmount, string Username) {
		_DateTime = Datime;
		_SuceBal = surceTrans;
		_DecsBal = DecrsTrans;
		_Amount = Amount;
		_surceAmount = surceAmount;
		_DecsAmount = DecrsAmount;
		_Username = Username;
	}
public:

	static void transferlogScreen() {
		
		vector<clsTransferLog> Vlod = _loadLOginRegister();
		clsScreen::_drowHeaderScreen("Transfer log History", "(" + to_string(Vlod.size()) + ")" + "Users");

		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n";

		cout << setw(8) << left << "" << "| " << left << setw(20) << "Date Time";
		cout << "| " << left << setw(8) << "S.Acc";
		cout << "| " << left << setw(8) << "d.Acc";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(8) << "s.Balence";
		cout << "| " << left << setw(8) << "d.Balence";
		cout << "| " << left << setw(8) << "User Name" << endl;
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n\n";

		if (Vlod.size() == 0) {
			cout << "\n\t\t\t\t The date of History is not found ....:( \n";
		}
		else {
			for (clsTransferLog& C : Vlod) {
				cout << setw(8) << left << "";
				_printInfoOfClient(C);
			}
		}
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n";
	}
	
};

