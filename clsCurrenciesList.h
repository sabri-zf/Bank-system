#pragma once
#include<iostream>
#include"clsString.h"
#include"clsScreen.h"
#include<iomanip>
#include<vector>
#include"clsCurrency.h"
class clsCurrenciesList :protected clsScreen
{
private:
	static void _printInfoOfCurrencies(clsCurrency Curr) {
		cout << "| " << setw(40) << left << Curr.GetCountry();
		cout << "| " << setw(8) << left << Curr.GetCurrencCode();
		cout << "| " << setw(45) << left << Curr.GetCurrencName();
		cout << "| " << setw(20) << left << Curr.GetRate();
		cout << endl;
	}
public:
	static void ShowCrrencyList() {
		vector<clsCurrency> Vcurre = clsCurrency::GetcurrencyList();
		clsScreen::_drowHeaderScreen("Currencies list ", "(" + to_string(Vcurre.size()) + ")");
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n";

		cout << setw(8) << left << "" << "| " << left << setw(40) << "Country";
		cout << "| " << left << setw(8) << "code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(20) << "Rate($1)"<<endl;
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n\n";

		if (Vcurre.size() == 0) {
			cout << "\n\t\t\t\t The date of Currencies is not found ....:( \n";
		}
		else {
			for (clsCurrency& Curr : Vcurre) {
				cout << setw(8) << left << "";
				_printInfoOfCurrencies(Curr);
			}
		}
		cout << setw(8) << left << "" << "_______________________________________________________________________";
		cout << "________________________________\n";
	}
};

