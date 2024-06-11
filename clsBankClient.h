#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsString.h"
#include"clsPerson.h"
#include<vector>
#include<fstream>
#include"GlobalDec.h"

using namespace std;

class clsBankClient:public clsPerson
{
private:
	string _AccountNumber;
	int _AccountBalenc;
	string _PinCode;
	bool _MarkDeleteClient=false;
	
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewClient = 2 };
	enMode _Mode;
	string _transferlogIn(int Amount ,clsBankClient clientTo, string seprtor="#//#") {
		string word = "";
		word += clsDate::DateToString(clsDate()) + " - ";
		word += clsDate::TimeToString(clsDate()) + seprtor;
		word += _AccountNumber + seprtor;
		word += clientTo._AccountNumber + seprtor;
		word += to_string(Amount) + seprtor;
		word += to_string(_AccountBalenc) + seprtor;
		word += to_string(clientTo._AccountBalenc) + seprtor;
		word += currentUser.UserName;

		return word;

	}
	static clsBankClient _convertClientToObject(string S1) {
		vector<string> Vclient = clsString::splitString(S1, "#//#");

		return clsBankClient(UpdateMode, Vclient[0], Vclient[1], Vclient[2], Vclient[3], Vclient[4], Vclient[5], stoi(Vclient[6]));
	}
	static clsBankClient _GetEmptyClientObject() {

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static	vector<clsBankClient> _LoadDataClientFromFile() {
		vector <clsBankClient> Vclient;
		fstream FreadData;

		FreadData.open("client.txt", ios::in);

		if (FreadData.is_open()) {
		
			string line = "";
			while (getline(FreadData, line)) {
				if (line != "") {
				clsBankClient client = _convertClientToObject(line);
				Vclient.push_back(client);
				}
			}
			FreadData.close();
		}
		return Vclient;
	}
	string _converclinetToLine(clsBankClient Client, string seprater = "#//#") {
		string Word = "";
		Word += Client.FirstName + seprater;
		Word += Client.LastName + seprater;
		Word += Client.Phone + seprater;
		Word += Client.Email + seprater;
		Word += Client.GetAccountNumber() + seprater;
		Word += Client.PinCode + seprater;
		Word += to_string(Client.Belence);

		return Word;
	}
	 void _saveClientToFile(vector<clsBankClient> VClient) {
		fstream fSave;
		fSave.open("client.txt", ios::out);
		if (fSave.is_open()) {
			string line = "";
			for (clsBankClient& client : VClient) {

				if (client._MarkDeleteClient == false) {
				line = _converclinetToLine(client);
				fSave << line << endl;
				}
			}
			fSave.close();
		}
	}
	void _Update() {
		vector<clsBankClient> _VreadData;
		_VreadData = _LoadDataClientFromFile();

		for (clsBankClient& C : _VreadData) {
			if (C.GetAccountNumber() == GetAccountNumber()) {
				C = *this;
				break;
			}
		}

		_saveClientToFile(_VreadData);
	}
	void _AddClient() {
		_AddDataLineToFile(_converclinetToLine(*this));
	}
	void _AddDataLineToFile(string line) {
		char ans;
		cout << "Are you sure ,Do you want add this client ? ";
		cin >> ans;
		if (tolower(ans) == 'y') {
			_SaveAddNewClientToFile(line, "client.txt", false);
		}
		else {
			*this = _GetEmptyClientObject();
		}
	}
	void _SaveAddNewClientToFile(string Line ,string nameFile = "client.txt",bool typeTransfer = true) {
		fstream fSaveAdd;

		fSaveAdd.open(nameFile, ios::out | ios::app);
		if (fSaveAdd.is_open()) {
			if (typeTransfer) {
				fSaveAdd << Line << endl ;

			}
			else {

			fSaveAdd << endl << Line ;
			}
			
			fSaveAdd.close();
		
		}
	}
	bool _deleteClient() {
		vector<clsBankClient> VClients;
		VClients = _LoadDataClientFromFile();

		for (clsBankClient& C : VClients) {
			if (C.GetAccountNumber() == _AccountNumber) {
				C._MarkDeleteClient = true;
				break;
			}
		}
		_saveClientToFile(VClients);
		*this = _GetEmptyClientObject();
		return true;
	}

public:

	clsBankClient(enMode Mode, string firstName, string lastName, string phone,string email, string AccNum, string pinCode, int AccBele)
		:clsPerson(firstName, lastName, phone, email) {
		_Mode = Mode;
		_PinCode = pinCode;
		_AccountNumber = AccNum;
		_AccountBalenc = AccBele;
	}

	string GetAccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string pinCode) {
		_PinCode = pinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;


	void SetAccountBelence (int Beleance) {
		_AccountBalenc = Beleance;
	}
	int GetAccountBelence() {
		return _AccountBalenc;
	}

	__declspec(property(get = GetAccountBelence, put = SetAccountBelence))int Belence;

	 bool isEmpty() {
		 return (enMode::EmptyMode == _Mode);
	}

	static clsBankClient Find(string AccountNum) {
		fstream GetData;
		GetData.open("client.txt", ios::in);
		if (GetData.is_open()) {

			string line = "";
			while (getline(GetData, line)) {
				clsBankClient Client = _convertClientToObject(line);
				if (Client.GetAccountNumber() == AccountNum) {
					GetData.close();
					return Client;
				}
			}
			GetData.close();
			}

		return _GetEmptyClientObject();
		
	}
	static  clsBankClient Find(string AccountNum,string PinCode) {
		vector<clsBankClient> Vclients;

		fstream GetData;
		GetData.open("client.txt", ios::in);
		if (GetData.is_open()) {

			string line = "";
			while (getline(GetData, line)) {
				clsBankClient Client = _convertClientToObject(line);
				if ((Client.GetAccountNumber() == AccountNum) && (Client.GetPinCode() == PinCode)) {
					GetData.close();
					return Client;
				}
			}
			GetData.close();

		}

		return _GetEmptyClientObject();

	}

	enum enSave { svFailEmotyObject = 0,svSuccseefullyObject = 1 };
	 enSave Save() {
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:

			return enSave::svFailEmotyObject;

		case clsBankClient::UpdateMode:

			_Update();
			return enSave::svSuccseefullyObject;

		case clsBankClient::AddNewClient:

			if (!clsBankClient::IsClientExist(_AccountNumber)) {
				return enSave::svFailEmotyObject;
			}
			else {
				_AddClient();
				_Mode = UpdateMode;
				return enSave::svSuccseefullyObject;
			}
		default:
			return svFailEmotyObject;
			break;
		}
		
	}

	 static clsBankClient GetAddClient(string AccountNum) {
		 return clsBankClient(AddNewClient, "", "", "", "", AccountNum, "", 0);
	 }

	static bool IsClientExist(string AccNum) {
		clsBankClient Client1 =clsBankClient::Find(AccNum);

		return (Client1.isEmpty());
	}

	 bool Delete() {
		return _deleteClient();
	}

	 static vector<clsBankClient> GetClients() {
		 return _LoadDataClientFromFile();
	 }
	 static int GetTotalBelance() {
		 vector<clsBankClient> Vclient = clsBankClient::GetClients();
		 int ToTal = 0;
		 for (clsBankClient& C : Vclient) {
			 ToTal += C.Belence;
		 }

		 return ToTal;
	 }

	  void DipositAmount(int Amount) {
		 _AccountBalenc += Amount;
		 Save();
	 } 
	  bool WithDrowAmount(int Amount) {
		  if (Amount > _AccountBalenc) {
			  return false;
		  }
		  else {
		 _AccountBalenc -= Amount;
		 Save();
		 return true;
		  }
	 }

	  bool transfer(int Amount, clsBankClient& clientTransfer) {
		  if (Amount > _AccountBalenc) {
			  false;
		  }
		  else {
			  WithDrowAmount(Amount);
			  clientTransfer.DipositAmount(Amount);
			  _SaveAddNewClientToFile(_transferlogIn(Amount, clientTransfer), "trensferLogin.txt");
			  return true;
		  }

	  }
	 void print() {
	/*	cout << "Client Card : \n";
		cout << "___________________________________\n";
		cout << "Account Number : " << _AccountNumber << endl;
		cout << "First Name     : " << FirstName << endl;
		cout << "Last  Name     : " << LastName << endl;
		cout << "Full  Name     : " << fullName() << endl;
		cout << "Email          : " << Email << endl;
		cout << "Phone          : " << Phone << endl;
		cout << "Pin Code       : " << _PinCode << endl;
		cout << "AccountBelance : " << _AccountBalenc << endl;
		cout << "___________________________________\n";*/
	}


};
