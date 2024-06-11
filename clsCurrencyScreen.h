#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsCurrenciesList.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrency.h"
#include"clsCalculaterCurrency.h"
class clsCurrencyScreen:protected clsScreen
{
private:
	enum eOption { eSowlist = 1, eFind = 2, eUpdate = 3, eCala = 4, eExit = 5 };
	static void _GoBackToMenuCurrecy() {
		cout << "Enter Any Key To Go BACK....\n";
		system("pause>0");
		ShowCurrencyScreen();
	}

	static void _ShowCurreList() {
		clsCurrenciesList::ShowCrrencyList();
	}
	static void _ShowCurreFind() {
		clsFindCurrency::findCrency();
	}
	static void _ShowCurreUpdate() {
		clsUpdateCurrency::updateCurrncey();
	}
	static void _ShowCurreCala() {
		clsCalculaterCurrency::CalculaterCurrency();
	}

	static void _performansMainScreen(eOption Val) {
		switch (Val)
		{
		case clsCurrencyScreen::eSowlist:
			system("cls");
			_ShowCurreList();
			_GoBackToMenuCurrecy();
			break;
		case clsCurrencyScreen::eFind:
			system("cls");
			_ShowCurreFind();
			_GoBackToMenuCurrecy();
			break;
		case clsCurrencyScreen::eUpdate:
			system("cls");
			_ShowCurreUpdate();
			_GoBackToMenuCurrecy();
			break;
		case clsCurrencyScreen::eCala:
			system("cls");
			_ShowCurreCala();
			_GoBackToMenuCurrecy();
			break;
		case clsCurrencyScreen::eExit:
			break;
		}

	}
public:
	static void ShowCurrencyScreen() {
		system("cls");
		clsScreen::_drowHeaderScreen("Main Currency Screen");
		cout << setw(37) << left << "" << "_________________________________________________\n";
		cout << setw(37) << left << "" << "\t\t  Menu Scrren Option\n";
		cout << setw(37) << left << "" << "_________________________________________________\n";

		cout << setw(37) << left << "" << "\t\t[1] Show Currency List   : \n";
		cout << setw(37) << left << "" << "\t\t[2] Show Find Cureency    : \n";
		cout << setw(37) << left << "" << "\t\t[3] Show UpDate Cureency  : \n";
		cout << setw(37) << left << "" << "\t\t[4] Show Cureency Calculater  : \n";
		cout << setw(37) << left << "" << "\t\t[5] Go Main Menu -> \n\n";
		cout << setw(37) << left << "" << "\tShooes any Option Between [1-5] :";

		_performansMainScreen((eOption)clsInputValidate::ReadIntNumberBetween(1, 5));

	}
};

