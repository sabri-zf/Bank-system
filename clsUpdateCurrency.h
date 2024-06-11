#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
class clsUpdateCurrency:protected clsScreen
{
private:
	static void _printFind(clsCurrency curr) {
		cout << "\ncurrency Is Found :)\n";
		cout << "\nCurrency Card\n";
		cout << "++++++++++++++++++++++++++\n";
		cout << "Country  = " << curr.GetCountry() << endl;
		cout << "Code     = " << curr.GetCurrencCode() << endl;
		cout << "Name     = " << curr.GetCurrencName() << endl;
		cout << "Rate($1) = " << curr.GetRate() << endl;
		cout << "++++++++++++++++++++++++++\n\n";
	}

public:
	static void updateCurrncey() {
		clsScreen::_drowHeaderScreen("UpDate Currency Screen ");
		cout << "\n Enter currency Code ";
		string _code = clsInputValidate::ReadString();

		while (!clsCurrency::IscurrencyExist(_code)) {
			cout << " Error Currency Code [" << _code << "] is not Found , pleses enter another code ";
			_code = clsInputValidate::ReadString();
		}

		clsCurrency curr1 = clsCurrency::FindByCode(_code);
		_printFind(curr1);

		char ans;
		cout << "Are you sure ,do you want Update currency ? , Enter (Y|N) ";
		cin >> ans;

		if (toupper(ans) == 'Y') {

			cout << "\n\n-----------------\n";
			cout << " Update currency : \n";
			cout << "-----------------\n";
			float NewRate;
			cout << "\nEnter New Rate ? ";
			NewRate = clsInputValidate::ReadDubNumber();
			curr1.UpdateRate(NewRate);

			cout << "\n\n UpDate Rate is Suceesfully ;) \n\n";
			_printFind(curr1);
		}

	}

};

