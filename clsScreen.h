#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include<iomanip>
#include "clsUser.h"
#include "GlobalDec.h"
#include"clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _drowHeaderScreen(string Title, string Descreabtion="") {
		cout << setw(37) << left<<"" << "------------------------------------------------\n";
		cout << setw(37) << left << "" << "\t\t\t" << Title<<endl;
		if (Descreabtion != "") {
			cout << setw(37) << left << "" << "\t\t\t" << Descreabtion << endl;
		}
		cout <<setw(37) << left<<"" << "User : " << currentUser.UserName << endl;
		
		cout << setw(37) << left << "" << "Date : " << clsDate::DateToString(clsDate()) << endl;
		

		cout << setw(37) << left<<"" << "------------------------------------------------\n";

		
	}
	static void _printInfo(clsBankClient client) {
		cout << "Client Card : \n";
		cout << "___________________________________\n";
		cout << "Account Number : " << client.GetAccountNumber() << endl;
		cout << "First Name     : " << client.FirstName << endl;
		cout << "Last  Name     : " << client.LastName << endl;
		cout << "Full  Name     : " << client.fullName() << endl;
		cout << "Email          : " << client.Email << endl;
		cout << "Phone          : " << client.Phone << endl;
		cout << "Pin Code       : " << client.PinCode << endl;
		cout << "AccountBelance : " << client.Belence << endl;
		cout << "___________________________________\n";
	}

	static void _printInfoUser(clsUser client) {
		cout << "Client Card : \n";
		cout << "___________________________________\n";
		cout << "User  Name     : " << client.UserName << endl;
		cout << "First Name     : " << client.FirstName << endl;
		cout << "Last  Name     : " << client.LastName << endl;
		cout << "Full  Name     : " << client.fullName() << endl;
		cout << "Email          : " << client.Email << endl;
		cout << "Phone          : " << client.Phone << endl;
		cout << "Pin Code       : " << client.Password << endl;
		cout << "Permission     : " << client.GetPermission() << endl;
		cout << "___________________________________\n";
	}

 static	bool checkpermisonRight(clsUser::epermission permission) {
	 if (!currentUser.checkPerimssion(permission)) {
		 cout << setw(37) << left << "" << "--------------------------------------------------------\n";
		 cout << setw(37) << left << "" << "\tAccses Do Not Pleses Contact With Admin !\n";
		 cout << setw(37) << left << "" << "--------------------------------------------------------\n";
		 return false;
	 }
	 else {
		 return true;
	 }
	}
};

