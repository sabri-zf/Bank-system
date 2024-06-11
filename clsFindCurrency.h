#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsCurrencyScreen.h"
class clsFindCurrency:protected clsScreen
{
private:
	enum eFind{eByCode=1,eByCountery =2};

	static void _GoBackMain() {
		cout << "Plaese Enter any key to go back main...";
		system("pause>0");
	}

	static void _printFind(clsCurrency curr) {
		cout << "currency Is Found :)\n";
		cout << "\nCurrency Card\n";
		cout << "++++++++++++++++++++++++++\n";
		cout << "Country  = " << curr.GetCountry() << endl;
		cout << "Code     = " << curr.GetCurrencCode() << endl;
		cout << "Name     = " << curr.GetCurrencName() << endl;
		cout << "Rate($1) = " << curr.GetRate() << endl;
		cout << "++++++++++++++++++++++++++\n\n";
	}
	static void _findByCode() {
		cout << "\nEnter code Of Country ? ";
		string _Code = clsInputValidate::ReadString();
		while (!clsCurrency::IscurrencyExist(_Code)) {
			cout << "This code is not Found , Please enter another Code ";
			char ans;
			cout << "\n\n Do You Want serche agin ? ";
			cin >> ans;
			if (toupper(ans) == 'Y') {
				cout << "\nEnter code Of Country ? ";
				_Code = clsInputValidate::ReadString();
			}
			else {
				return;
			}
		}

		clsCurrency curr1 = clsCurrency::FindByCode(_Code);
		_printFind(curr1);

		cout << "Find is Suceessfully <:>\n";
	}
	static void _findByCountry() {
		cout << "\nEnter Country ? ";
		string _country = clsInputValidate::ReadString();
		while (!clsCurrency::IscurrencyExist(_country,true)) {
			cout << "This Country is not Found , Please enter another Country ";
			char ans;
			cout << "\n\n Do You Want serche agin ? ";
			cin >> ans;
			if (toupper(ans) == 'Y') {
				cout << "\nEnter Country ? ";
			_country = clsInputValidate::ReadString();
			}
			else {
				return;
			}
		}

		clsCurrency curr2 = clsCurrency::FindByCountry(_country);
		_printFind(curr2);

		cout << "Find is Suceessfully <:>\n";
	}

	static void _checkOutput(eFind val) {
		switch (val)
		{
		case clsFindCurrency::eByCode:
			_findByCode();
			break;
		case clsFindCurrency::eByCountery:
			_findByCountry();
			break;
		}
	}
public:
	static void findCrency() {
		clsScreen::_drowHeaderScreen("Find Crrency Screen");
		cout << "Find By : Code[1] or contry [2] ";
		_checkOutput(eFind(clsInputValidate::ReadIntNumberBetween(1, 2)));
	}
};

