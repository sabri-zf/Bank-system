#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"clsDate.h"
#include"GlobalDec.h"
#include"clsUlit.h"
class clsRegisterLogin:protected clsScreen
{
private:
	string _DateTime, _UserName, _Password, _permisson;

	static void _printInfoOfClient(clsRegisterLogin Client) {
	
		cout << "| " << setw(30) << left << Client._DateTime;
		cout << "| " << setw(20) << left << Client._UserName;
		cout << "| " << setw(12) << left << Client._Password;
		cout << "| " << setw(10) << left << Client._permisson;
		cout << endl;
	}

	static string _ConvertInfoUserLogInToString() {
		return clsDate::DateToString(clsDate()) + " - " + clsDate::TimeToString(clsDate())+"#//#" + currentUser.UserName
			+ "#//#" + currentUser.Password + "#//#" + to_string(currentUser.permission);
	}
	static clsRegisterLogin _convertUserHistoryToObject(string line, string spreter = "#//#") {
		vector<string> Vstr;
		Vstr = clsString::splitString(line, spreter);

		return clsRegisterLogin(Vstr[0], Vstr[1], Vstr[2], Vstr[3]);
	}
	static void _saveLoginToFile() {
		fstream SVlogin;
		SVlogin.open("loginRegster.txt", ios::out | ios::app);
		if (SVlogin.is_open()) {
			string line = _ConvertInfoUserLogInToString();
			SVlogin << line << endl;
		}
	}
	static vector<clsRegisterLogin> _loadLOginRegister() {
		fstream LoadData;
		vector<clsRegisterLogin> VresgLoad;
		LoadData.open("loginRegster.txt", ios::in);
		if (LoadData.is_open()) {
			string line = "";
			while (getline(LoadData, line)) {
				if (line != "") {

				clsRegisterLogin User = _convertUserHistoryToObject(line);

				VresgLoad.push_back(User);
				}
			}
			LoadData.close();
		}
		return VresgLoad;
	}
public:

	clsRegisterLogin(string DateTime, string UserName, string Password, string permisson) {
		_DateTime = DateTime;
		_UserName = UserName;
		_Password = Password;
		_permisson = permisson;
	}
	static void LoginHistory() {
		_saveLoginToFile();

		if (!checkpermisonRight(clsUser::eShowloginRegster)) {
			return;
		}

		vector<clsRegisterLogin> Vlod = _loadLOginRegister();
		clsScreen::_drowHeaderScreen("Register Log In History", "(" + to_string(Vlod.size() )+ ")"+"Users");
		
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n";

		cout << setw(8) << left << "" << "| " << left <<setw(30) << "Date Time";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(12) << "PassWord";
		cout << "| " << left << setw(10) << "Permission" << endl;
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n\n";

		if (Vlod.size() == 0) {
			cout << "\n\t\t\t\t The date of History is not found ....:( \n";
		}
		else {
			for (clsRegisterLogin& C : Vlod) {
				cout << setw(8) << left << "";
				_printInfoOfClient(C);
			}
		}
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n";
	}
		

	
};

