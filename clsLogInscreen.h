#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"GlobalDec.h"
#include"clsMainScreen.h"
#include"clsRegisterLogin.h"

class clsLogInscreen:protected clsScreen
{
private:
	static bool _logIn() {
		string Username, Password;
		short countFail = 0;
		bool failLogin = false;
		do {
			system("cls");
			clsScreen::_drowHeaderScreen("Log In Screen");
			
			if (failLogin) {
				countFail++;
				cout << "Invalid UserName & password , try agian You have ("<<3-countFail<<") tryes \n";
			}

			cout << "\n Enter User name : ";
			Username = clsInputValidate::ReadString();
			cout << "\n Enter Password : ";
			Password = clsInputValidate::ReadString();
			
			currentUser = clsUser::Find(Username, Password);
			failLogin = currentUser.isEmpty();

			if (countFail == 3) {
				cout << "louck LogIn After (3) trail(s) !\n";
				return false;
			}

		} while (failLogin);

		clsMainScreen::ShowMainMenuList();
	}
public:
	static bool LoginAccountUser() {
		
		return _logIn();
	}
};

