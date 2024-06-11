#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsAddNewUser:protected clsScreen
{
private:
	static int _PermissionValue() {
		int Permission = 0;
		char ans;
		cout << "Are you sure ,do you want give the user accses All Mange? ";
		cin >> ans;
		if (toupper(ans) == 'Y') {
			Permission = -1;
			return Permission;
		}

		cout << "\nWhat do you want need accse for User ? :\n";
		ans = 0;
		cout << "Are you sure ,do you want accses of list clinte ? ";
		cin >> ans;

		if (toupper(ans) == 'Y') {
			Permission += clsUser::eShowList;
		}
		ans = 0;
		cout << "Are you sure ,do you want accses of Add new Client ? ";
		cin >> ans;

		if (toupper(ans) == 'Y') {
			Permission += clsUser::eShowAddNew;
		}
		ans = 0;
		cout << "Are you sure ,do you want accses of Delet Client ? ";
		cin >> ans;

		if (toupper(ans) == 'Y') {
			Permission += clsUser::eShowDelete;
		}
		ans = 0;
		cout << "Are you sure ,do you want accses of Update Client ? ";
		cin >> ans;

		if (toupper(ans) == 'Y') {
			Permission += clsUser::eShowUpdate;
		}
		ans = 0;
		cout << "Are you sure ,do you want accses of Find Client ? ";
		cin >> ans;

		if (toupper(ans) == 'Y') {
			Permission += clsUser::eShowFind;
		}
		ans = 0;
		cout << "Are you sure ,do you want accses of Transaction ? ";
		cin >> ans;

		if (toupper(ans) == 'Y') {
			Permission += clsUser::eShowTransaction;
		}
		ans = 0;
		cout << "Are you sure ,do you want accses of Mange User ? ";
		cin >> ans;

		if (toupper(ans) == 'Y') {
			Permission += clsUser::eShowMangeUser;
		}
		ans = 0;
		cout << "Are you sure ,do you want accses of Register screen  ? ";
		cin >> ans;

		if (toupper(ans) == 'Y') {
			Permission += clsUser::eShowloginRegster;
		}

		return Permission;
	}
	static void _printDataOFUser(clsUser& U) {
		cout << "\n Enter First Name : ";
		U.FirstName = clsInputValidate::ReadString();
		cout << "\n Enter Last Name : ";
		U.LastName = clsInputValidate::ReadString();
		cout << "\n Enter Phone : ";
		U.Phone = clsInputValidate::ReadString();
		cout << "\n Enter Email : ";
		U.Email = clsInputValidate::ReadString();
		cout << "\n Enter Password : ";
		U.Password = clsInputValidate::ReadString();
		cout << "\n Prenission Option : \n";
		U.permission = _PermissionValue();
	}
public:
	static void AddNewUserScreen() {
		clsScreen::_drowHeaderScreen("Add New Users");
		cout << "Enter Usear Name: ";
		string Username = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(Username)) {
			cout << "the UsareName["<<Username <<"]alreday exist , Try Agian ..";
			Username = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::GetAddNewUser(Username);
		_printDataOFUser(User1);

		clsUser::eSaveMode SaveResult;

		SaveResult = User1.Save();
		switch (SaveResult)
		{
		case clsUser::eSvFail:
			cout << "\nsave User IS Fail .. :(\n";
			break;
		case clsUser::eSvSuccessfully:
			cout << "\nsave User IS Succseefully .. :)\n";
			clsScreen::_printInfoUser(User1);
			break;
		case clsUser::eSvFailUserExist:
			cout << "\nSorry The User is Already is Exist..!!\n";
			break;
		}
	}
};

