#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"

class clsUser:public clsPerson
{
private:
	enum _eMode { eEmptyMode = 1, eUpdateMode = 2, eAddNewMode = 3 };
	_eMode _Mode;
	string _UserName;
	string _Password;
	int _Permission;

	bool _MarkDeleteUser = false;


	static clsUser _convertUserToObject(string S1,string spriter="#//#") {
		vector<string> Vclient = clsString::splitString(S1, spriter);

		return clsUser(eUpdateMode, Vclient[0], Vclient[1], Vclient[2], Vclient[3], Vclient[4], Vclient[5], stoi(Vclient[6]));
	}
	string _converUserToLine(clsUser Client, string seprater = "#//#") {
		string Word = "";
		Word += Client.FirstName + seprater;
		Word += Client.LastName + seprater;
		Word += Client.Phone + seprater;
		Word += Client.Email + seprater;
		Word += Client.UserName + seprater;
		Word += Client.Password + seprater;
		Word += to_string(Client.GetPermission());

		return Word;
	}

	static clsUser _GetEmptyUserObject() {

		return clsUser (_eMode::eEmptyMode, "", "", "", "", "", "", 0);
	}

	static	vector<clsUser> _LoadDataUserFromFile() {
		vector <clsUser> Vclient;
		fstream FreadData;

		FreadData.open("users.txt", ios::in);

		if (FreadData.is_open()) {

			string line = "";
			while (getline(FreadData, line)) {
				if (line != "") {
					clsUser client = _convertUserToObject(line);
					Vclient.push_back(client);
				}
			}
			FreadData.close();
		}
		return Vclient;
	}
	void _saveUserToFile(vector<clsUser> VClient) {
		fstream fSave;
		fSave.open("users.txt", ios::out);
		if (fSave.is_open()) {
			string line = "";
			for (clsUser& client : VClient) {

				if (client._MarkDeleteUser == false) {
					line = _converUserToLine(client);
					fSave << line << endl;
				}
			}
			fSave.close();
		}
	}

	void _Update() {
		vector<clsUser> Vuser = _LoadDataUserFromFile();

		for (clsUser& U : Vuser) {
			if (U.UserName == GetUserName()) {
				 U = *this;
				break;
			}
		}
		_saveUserToFile(Vuser);
	}
	void _AddUser() {
		_AddDataLineToFile(_converUserToLine(*this));
	}
	void _AddDataLineToFile(string line) {
		char ans;
		cout << "Are you sure ,Do you want add this client ? ";
		cin >> ans;
		if (tolower(ans) == 'y') {
			_SaveAddNewUserToFile(line);
		}
		else {
			*this = _GetEmptyUserObject();
		}
	}
	void _SaveAddNewUserToFile(string Line) {
		fstream fSaveAdd;

		fSaveAdd.open("users.txt", ios::out | ios::app);
		if (fSaveAdd.is_open()) {

			fSaveAdd << endl << Line;
			fSaveAdd.close();

		}
	}
	bool _deleteUser() {
		vector<clsUser> VClients;
		VClients = _LoadDataUserFromFile();

		for (clsUser& C : VClients) {
			if (C.UserName == _UserName) {
				C._MarkDeleteUser = true;
				break;
			}
		}
		_saveUserToFile(VClients);
		*this = _GetEmptyUserObject();
		return true;
	}
public:
	enum epermission {
		eAll = -1, eShowList = 1, eShowAddNew = 2, eShowDelete = 4,
		eShowUpdate = 8, eShowFind = 16, eShowTransaction = 32, eShowMangeUser = 64, eShowloginRegster = 128
	};

	clsUser(_eMode Mode, string FirstName, string LastName, string Email, string Phone, string UsreName, string Password,int Permission)
		:clsPerson(FirstName, LastName, Phone, Email)
	{
		_Mode = Mode;
		_UserName = UsreName;
		_Password = Password;
		_Permission = Permission;
	}

	void SetUserName(string UserName) {
		_UserName = UserName;
	}
	string GetUserName() {
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName))string UserName;

	void SetPassword(string Password) {
		_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Password;
	void SetPermission(int premission) {
		_Permission = premission;
	}
	int GetPermission() {
		return _Permission;
	}
	__declspec(property(get = GetPermission, put = SetPermission))int permission;


	bool GetMarkDelete() {
		return _MarkDeleteUser;
	}
	bool isEmpty() {
		return (_Mode == _eMode::eEmptyMode);
	}

	static clsUser Find(string Username) {
		fstream GetData;
		GetData.open("users.txt", ios::in);
		if (GetData.is_open()) {

			string line = "";

			while (getline(GetData, line)) {
				clsUser User = _convertUserToObject(line);
				if (User.UserName == Username) {
					GetData.close();
					return User;
				}
			}
			GetData.close();
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string Username,string PassWord) {
		fstream GetData;
		GetData.open("users.txt", ios::in);
		if (GetData.is_open()) {

			string line = "";

			while (getline(GetData, line)) {
				clsUser User = _convertUserToObject(line);
				if (User.UserName == Username && User.Password == PassWord) {
					GetData.close();
					return User;
				}
			}
			GetData.close();
		}
		return _GetEmptyUserObject();
	}

	enum eSaveMode{eSvFail =1,eSvSuccessfully=2,eSvFailUserExist=3};
	 eSaveMode Save() {
		 switch (_Mode)
		 {
		 case clsUser::eEmptyMode:
			 if (isEmpty()) {
				 return eSvFail;
			 }
			 break;
		 case clsUser::eUpdateMode:
			 _Update();
			 return eSvSuccessfully;
			 break;
		 case clsUser::eAddNewMode:
			 if (clsUser::IsUserExist(_UserName)) {
				 return eSvFailUserExist;
			 }
			 else {
				 _AddUser();
				 _Mode = eUpdateMode;
				 return eSvSuccessfully;
			 }
			 break;
		 }
	}

	 static clsUser GetAddNewUser(string Username) {
		 return clsUser(eAddNewMode, "", "", "", "", Username, "", -1);
	 }
	 bool Delete() {
		 return _deleteUser();
	 }

	 static vector<clsUser> GetUsers() {
		 return _LoadDataUserFromFile();
	 }


	 static bool IsUserExist(string AccountNumber) {
		 clsUser User1 = clsUser::Find(AccountNumber);
		 return(!User1.isEmpty());
	 }

	  bool checkPerimssion(epermission perm) {

		 if (this->permission == epermission::eAll) {
			 return true;
		 }



		 if ((perm & this->permission) == perm) {

			 return true;
		 }
		 else {

			 return false;
		 }
	 }

};

