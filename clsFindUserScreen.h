#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsFindUserScreen:protected clsScreen
{
public:
	static void FindUsrerScreen() {
		clsScreen::_drowHeaderScreen("Find User Screen");
		cout << "\n Enter UserName : ";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName)) {

			cout << "The UserName [" << UserName << "] Is Not Found, Enter another choice ...";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User1 = clsUser::Find(UserName);
		clsScreen::_printInfoUser(User1);
	}

};

