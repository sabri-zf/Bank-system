#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsDeleteUserScreen:protected clsScreen
{
public :
	static void DeleteUser() {
		clsScreen::_drowHeaderScreen("Delete User Screen");

		cout << "Enter UserName : ";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName)) {
			cout << "Erorr Your [" << UserName << "] is Not Found ,please entr another ...";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);
		clsScreen::_printInfoUser(User1);

		char ans;
		cout << "\n\nAre you sure ,Do you want need delete User ? ";
		cin >> ans;

		if (toupper(ans) == 'Y') {
			if (User1.Delete()) {
				cout << "\nDelete User Is Successfully ;) , check Your List  \n";
				clsScreen::_printInfoUser(User1);
			}
			else {
				cout << "\nErorr Fail Delete User ! :( \n";

			}
		}
		else {
			cout << "\n The user is not Delete !!\n";
		}
	}
};

