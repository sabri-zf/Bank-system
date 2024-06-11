#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsListClients.h"
#include"clsAddNewClient.h"
#include"clsDeleteClient.h"
#include"clsUpdateClient.h"
#include"clsFindClient.h"
#include"clstransactionScreen.h"
#include"clsManageUserScreen.h"
#include"clsRegisterLogin.h"
#include"clsCurrencyScreen.h"


using namespace std;

class clsMainScreen:protected clsScreen
{
private:
	enum eOption{eShowList=1,eAddNew=2,eDelete=3,eUpdate=4,eFind=5,eTransaction=6,
		eMangUser=7,eRegister=8,eCurrencyScreen=9,eExit=10};
	static void _GoToBackMenuScreen() {
		system("pause");
		ShowMainMenuList();
	}

	static void _showClientList() {
		clsListClients::ShowclientList();
	}
	static void _showAddNewClient() {
		clsAddNewClient::AddNewClient();
	}
	static void _showDeleteClient() {
		clsDeleteClient::DeleteClient();
	}
	static void _showUpDateClient() {
		clsUpdateClient::UpdateClientInfo();
	}
	static void _showFindClient() {
		clsFindClient::FindClient();
	}
	static void _showTransaction() {
		clstransactionScreen::ShowTransactionScreen();
	}
	static void _showMangeUser() {
		clsManageUserScreen::ManageUsers();
	}
	static void RegisterLogIn() {
		clsRegisterLogin::LoginHistory();
	}
	static void _CurrencyScreen() {
		clsCurrencyScreen::ShowCurrencyScreen();
	}
	static void _showLogOut() {
		currentUser = clsUser::Find("", "");
	}

	static void _performansMainScreen(eOption Opt) {
		switch (Opt)
		{
		case clsMainScreen::eShowList:
			system("cls");
			_showClientList();
			_GoToBackMenuScreen();
			break;
		case clsMainScreen::eAddNew:
			system("cls");
			_showAddNewClient();
			_GoToBackMenuScreen();
			break;
		case clsMainScreen::eDelete:
			system("cls");
			_showDeleteClient();
			_GoToBackMenuScreen();
			break;
		case clsMainScreen::eUpdate:
			system("cls");
			_showUpDateClient();
			_GoToBackMenuScreen();
			break;
		case clsMainScreen::eFind:
			system("cls");
			_showFindClient();
			_GoToBackMenuScreen();
			break;
		case clsMainScreen::eTransaction:
			system("cls");
			_showTransaction();
			_GoToBackMenuScreen();
			break;
		case clsMainScreen::eMangUser:
			system("cls");
			_showMangeUser();
			_GoToBackMenuScreen();
			break;
		case clsMainScreen::eRegister:
			system("cls");
			RegisterLogIn();
			_GoToBackMenuScreen();
			break;
		case clsMainScreen::eCurrencyScreen:
			system("cls");
			_CurrencyScreen();
			_GoToBackMenuScreen();
			break;
		case clsMainScreen::eExit:
			system("cls");
			_showLogOut();
			break;
		}
	}
public:
	static void ShowMainMenuList() {
		system("cls");
		system("color F0");
		clsScreen::_drowHeaderScreen("Main Screen");
		cout << setw(37) << left<<"" << "_________________________________________________\n";
		cout << setw(37) << left<<"" << "\t\t  Menu Scrren Option\n";
		cout << setw(37) << left<<"" << "_________________________________________________\n";
							
		cout << setw(37) << left<<"" << "\t\t[1] Show Clients List   : \n";
		cout << setw(37) << left<<"" << "\t\t[2] Show Add New Client : \n";
		cout << setw(37) << left<<"" << "\t\t[3] Show Delete Client  : \n";
		cout << setw(37) << left<<"" << "\t\t[4] Show UpDate Client  : \n";
		cout << setw(37) << left<<"" << "\t\t[5] Show Find Client    : \n";
		cout << setw(37) << left<<"" << "\t\t[6] Show Transaction    : \n";
		cout << setw(37) << left<<"" << "\t\t[7] Show Mange User     : \n";
		cout << setw(37) << left<<"" << "\t\t[8] Show Regster LogIn  : \n";
		cout << setw(37) << left<<"" << "\t\t[9] Show currency Screen  : \n";
		cout << setw(37) << left<<"" << "\t\t[10] Log Out -> \n\n";
		cout << setw(37) << left<<"" << "\tShooes any Option Between [1-9] :";

		_performansMainScreen((eOption)clsInputValidate::ReadIntNumberBetween(1, 10));

	}
};

