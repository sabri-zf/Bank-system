#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUserList.h"
#include"clsAddNewUser.h"
#include"clsDeleteUserScreen.h"
#include"clsUpateIserScreen.h"
#include"clsFindUserScreen.h"
class clsManageUserScreen:clsScreen
{
private:
	enum eMangeUsers{elistUser=1,eAddNewUser=2,eDeleteUser=3,eUpdateUser=4,eFindUser=5,eExit=6};
	static void _GoToBackMangeUsers() {
		system("pause");
		ManageUsers();
	}

	static void _ShowListUsers() {
		clsUserList::ListUserScreen();
	}
	static void _ShowAddNewUsers() {
		clsAddNewUser::AddNewUserScreen();
	}
	static void _ShowDeleteUsers() {
		clsDeleteUserScreen::DeleteUser();
	}
	static void _ShowUpDateUsers() {
		clsUpateIserScreen::UpdateUser();
	}
	static void _ShowFindUsers() {
		clsFindUserScreen::FindUsrerScreen();
	}

	static void _performansMainScreen(eMangeUsers MangeOption) {
		switch (MangeOption)
		{
		case clsManageUserScreen::elistUser:
			system("cls");
			_ShowListUsers();
			_GoToBackMangeUsers();
			break;
		case clsManageUserScreen::eAddNewUser:
			system("cls");
			_ShowAddNewUsers();
			_GoToBackMangeUsers();
			break;
		case clsManageUserScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUsers();
			_GoToBackMangeUsers();
			break;
		case clsManageUserScreen::eUpdateUser:
			system("cls");
			_ShowUpDateUsers();
			_GoToBackMangeUsers();
			break;
		case clsManageUserScreen::eFindUser:
			system("cls");
			_ShowFindUsers();
			_GoToBackMangeUsers();
			break;
		case clsManageUserScreen::eExit:
			break;
		}
	}
public:
	static void ManageUsers() {
		if (!checkpermisonRight(clsUser::eShowMangeUser)) {
			return;
		}
		system("cls");
		clsScreen::_drowHeaderScreen("Manage Users Screen");
		cout << setw(37) << left << "" << "_________________________________________________\n";
		cout << setw(37) << left << "" << "\t\t  Menu Scrren Option\n";
		cout << setw(37) << left << "" << "_________________________________________________\n";

		cout << setw(37) << left << "" << "\t\t[1] Show Users List    : \n";
		cout << setw(37) << left << "" << "\t\t[2] Show Add New Users : \n";
		cout << setw(37) << left << "" << "\t\t[3] Show Delete Users  : \n";
		cout << setw(37) << left << "" << "\t\t[4] Show UpDate Users  : \n";
		cout << setw(37) << left << "" << "\t\t[5] Show Find Users    : \n";
		cout << setw(37) << left << "" << "\t\t[6] Main Menu -> \n\n";
		cout << setw(37) << left << "" << "\tShooes any Option Between [1-8] :";

		_performansMainScreen((eMangeUsers)clsInputValidate::ReadIntNumberBetween(1, 6));

	}
};

