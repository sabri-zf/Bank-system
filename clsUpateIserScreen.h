#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsUpateIserScreen:protected clsScreen
{
private:
	static int _PermissionValue() {
		int Permission = 0;
		char ans;
		cout << "\nAre you sure ,do you want give the user accses All Mange? ";
		cin >> ans;
		if (toupper(ans) == 'Y') {
			Permission = -1;
			return Permission;
		}

		cout << "\nWhat do you want need accse for User ? :\n\n";
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

		return Permission;
	}

	static void _RePrintDataOfUser(clsUser& User) {
		User.UserName;
		cout << "Enter first Name  ? ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter last Name ? ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Phone     ? ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Email     ? ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Pin Code  ? ";
		User.Password = clsInputValidate::ReadString();
		cout << "\npermission Options   \n\n";
		User.permission = _PermissionValue();
	}
public:
	static void UpdateUser() {
		clsScreen::_drowHeaderScreen("Update User Screen");
		cout << "\n Enter UserName : ";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName)) {

			cout << "The UserName [" << UserName << "] Is Not Found, Enter another choice ...";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User1 = clsUser::Find(UserName);
		clsScreen::_printInfoUser(User1);
		char ans;
		cout << "are you sure , Do you want update user ? ";
		cin >> ans;
		if (toupper(ans) == 'Y') {

			cout << "/n/n----- Update User Info ------\n\n";
			_RePrintDataOfUser(User1);

			clsUser::eSaveMode saveResult;
			saveResult = User1.Save();

			switch (saveResult)
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
		else {
			cout << "\n\nokay this is defualt info of User \n\n";

			clsScreen::_printInfoUser(User1);
		}
		
	}
};

