#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDiposit.h"
#include"clsWithDrow.h"
#include"clsTotalBalences.h"
#include"clsTransfer.h"
#include"clsTransferLog.h"
class clstransactionScreen:clsScreen
{
private:
	enum OptionMove{eDiposit=1,eWithDrow=2,eTotalBalence= 3,eTransfer=4,eTransferLog=5,eExit=6};
	static short _ReadOptionNumber() {
		short Val = 0;
		cout << "Shooes The Option of Number [1-6] ? ";
		Val = clsInputValidate::ReadIntNumberBetween(1, 6);

		return Val;
	}

	static void GotobackMenuTransaction() {
		cout << setw(37) << left << "" << "Click Enter To Go Back...<- ";
		system("pause>0");
		ShowTransactionScreen();
	}

	static void Diposit() {
		clsDiposit::DipositAccount();
	}
	static void withDrow() {
		clsWithDrow::WithdrowAccount();
	}
	static void TotalBelances() {
		clsTotalBalences::ShowTotalBalence();
	}

	static void transferScreen() {
		clsTransfer::TreansferSceen();
	}
	static void TransferLogScreen() {
		clsTransferLog::transferlogScreen();
	}

	static void _RuningOptions(OptionMove value) {
		switch (value)
		{
		case clstransactionScreen::eDiposit:
			system("cls");
			Diposit();
			GotobackMenuTransaction();
			break;
		case clstransactionScreen::eWithDrow:
			system("cls");
			withDrow();
			GotobackMenuTransaction();
			break;
		case clstransactionScreen::eTotalBalence:
			system("cls");
			TotalBelances();
			GotobackMenuTransaction();
			break;
		case clstransactionScreen::eTransfer:
			system("cls");
			transferScreen();
			GotobackMenuTransaction();
			break;
		case clstransactionScreen::eTransferLog:
			system("cls");
			TransferLogScreen();
			GotobackMenuTransaction();
			break;
		case clstransactionScreen::eExit:
			break;
		}
	}
public:
	static void ShowTransactionScreen() {
		if (!checkpermisonRight(clsUser::eShowTransaction)) {
			return;
		}
		system("cls");
		clsScreen::_drowHeaderScreen("Transaction Screen");

		cout << setw(37) << left << "" << "________________________________________\n";
		cout << setw(37) << left << "" << "\t\t Menu Transaction\n";
		cout << setw(37) << left << "" << "________________________________________\n";
		cout << setw(37) << left << "" << "\t\t[1] Diposit\n";
		cout << setw(37) << left << "" << "\t\t[2] WithDrow\n";
		cout << setw(37) << left << "" << "\t\t[3] Total blences\n";
		cout << setw(37) << left << "" << "\t\t[4] Transfer \n";
		cout << setw(37) << left << "" << "\t\t[5] TransferLog \n";
		cout << setw(37) << left << "" << "\t\t[6] Go To Main\n";
		cout << setw(37) << left << "" << "________________________________________\n";

		_RuningOptions((OptionMove)_ReadOptionNumber());


	}
};

