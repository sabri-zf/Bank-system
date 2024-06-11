#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
class clsCalculaterCurrency:protected clsScreen
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

	static string _RadeCode(string Num) {
		cout << "Enter currency [" << Num << "] Code ";
		string _code = clsInputValidate::ReadString();
		while (!clsCurrency::IscurrencyExist(_code)) {
			cout << "Error The Code of [" << _code << "] Is not found !!, Enter another ";
			_code = clsInputValidate::ReadString();
		};

		return _code;
	}
	static void _calcualterCurrncy(clsCurrency curr1,clsCurrency curr2) {
		float Amount = 0,Result = 0;
		cout << "Enter Amount of Exchange ";
		Amount = clsInputValidate::ReadDubNumber();


		if (curr2.GetCurrencCode() == "USD") {
			Result = ( Amount/ curr1.GetRate());
			cout << "Convert From \n";
			_printFind(curr1);
			
			cout << Amount << curr1.GetCurrencCode() << " = " << Result <<" "<< curr2.GetCurrencCode();
		}
		else {
			Result = (Amount / curr1.GetRate());
			cout << "Convert From \n";

			_printFind(curr1);
			cout << Amount << curr1.GetCurrencCode() << " = " << Result << " USD";

			Result *= curr2.GetRate();

			cout << "\n\nConvert USD To \n";

			_printFind(curr2);
			cout << Amount << curr1.GetCurrencCode() << " = " << Result <<" "<< curr2.GetCurrencCode();
		}
	}
public:
	static void CalculaterCurrency() {
			char ans = 'n';
		do {
			system("cls");
			clsScreen::_drowHeaderScreen("calcuater Currency Scrren ");

			clsCurrency curr1 = clsCurrency::FindByCode(_RadeCode("1"));
			clsCurrency curr2 = clsCurrency::FindByCode(_RadeCode("2"));

			 _calcualterCurrncy(curr1,curr2);

			cout << "\n\nAre you Calcuater Agian ? ";
			cin >> ans;
		} while (toupper(ans) == 'Y');
		
	}
};

