#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsScreen.h"
#include "clsPerson.h"
class clsUserList :protected clsScreen
{
private:
	static void _printInfoOfUsers(clsUser User) {
		cout << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(20) << left << User.fullName();
		cout << "| " << setw(12) << left << User.Email;
		cout << "| " << setw(20) << left << User.Phone;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << to_string(User.GetPermission());
		cout << endl;
	}
public:
	static void ListUserScreen() {
		
		vector<clsUser> Vclient;
		Vclient = clsUser::GetUsers();
		string Tital = "Users List";
		string SubTital = "(" + to_string(Vclient.size()) + ")" + "Users";

		clsScreen::_drowHeaderScreen(Tital, SubTital);
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n";

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Type";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions\n";
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n\n";

		if (Vclient.size() == 0) {
			cout << "\n\t\t\t\t The date of clients is not found ....:( \n";
		}
		else {
			for (clsUser& C : Vclient) {
				cout << setw(8) << left << "";
				_printInfoOfUsers(C);
			}
		}
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n";
	}
};
