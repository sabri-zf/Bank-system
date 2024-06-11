#pragma once
#include<iostream>
#include<string>
#include"clsDate.h"
#include"clsUlit.h"
#include"clsString.h"

using namespace std;
class clsInputValidate
{
public:
	static bool IsNumberBetween(short Num1, short Num2, short Num3) {
		if (Num1 >= Num2) {
			clsUlit::_Swap(Num1, Num2);
		}
		if ((Num1 <= Num3) && (Num2 >= Num3)) {
			return true;
		}
		return false;
	}
	static bool IsNumberBetween(int Num1, int Num2, int Num3) {
		if (Num1 >= Num2) {
			clsUlit::_Swap(Num1, Num2);
		}
		if ((Num1 <= Num3) && (Num2 >= Num3)) {
			return true;
		}
		return false;
	}
	static bool IsNumberBetween(double Num1, double Num2, double Num3) {
		if (Num1 >= Num2) {
			clsUlit::_Swap(Num1, Num2);
		}
		if (Num1 <= Num3 && Num2 >= Num3) {
			return true;
		}
		return false;
	}
	static bool IsNumberBetween(float Num1, float Num2, float Num3) {
		if (Num1 >= Num2) {
			clsUlit::_Swap(Num1, Num2);
		}
		if (Num1 <= Num3 && Num2 >= Num3) {
			return true;
		}
		return false;
	}

	static bool IsDateBetween(clsDate DateNow,clsDate Date1,clsDate Date2) {

		if (clsDate::IsDateOneBeforDateTwo(Date1,Date2)) {
			if (IsNumberBetween(Date1.day, Date2.day, DateNow.day))
				return true;
			else
				return false;
		}
		else {
			clsDate::_swapDate(Date1, Date2);
			IsDateBetween(DateNow, Date1, Date2);
		}
		return false;
	}

	static int ReadIntNumber(string MessageError = "Invalide Number , please enter agian ") {
		int Number;
		while (!(cin>>Number)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << MessageError<<" ";
		}
		return Number;
	}
	static short ReadInttNumber(string MessageError = "Invalide Number , please enter agian ") {
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << MessageError << " ";
		}
		return Number;
	}
	static float ReadFloatNumber(string MessageError = "Invalide Number , please enter agian ") {
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << MessageError << " ";
		}
		return Number;
	}
	static double ReadDubNumber(string MessageError = "Invalide Number , please enter agian ") {
		double Number;
		while (!(cin>>Number)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << MessageError<<" ";
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To,string messageErorr="Number is not withe range, enter again Number  ") {
		int Num = ReadIntNumber();
		while (!IsNumberBetween(From, To, Num))
		{
			cout << messageErorr;
			Num = ReadIntNumber();
		}

		return Num;
	}
	static short ReadIntNumberBetween(short From, short To, string messageErorr = "Number is not withe range, enter again Number  ") {
		short Num = ReadIntNumber();
		while (!IsNumberBetween(From, To, Num))
		{
			cout << messageErorr;
			Num = ReadIntNumber();
		}

		return Num;
	}

	static double ReadDoubleNumberBetween(double From, double To, string messageErorr = "Number is not withe range, enter again Number  ") {
		double Num = ReadDubNumber();
		while (!IsNumberBetween(From, To, Num))
		{
			cout << messageErorr;
			Num = ReadIntNumber();
		}

		return Num;
	}
	static float ReadDoubleNumberBetween(float From, float To, string messageErorr = "Number is not withe range, enter again Number  ") {
		float Num = ReadFloatNumber();

		while (!IsNumberBetween(From, To, Num))
		{
			cout << messageErorr;
			Num = ReadFloatNumber();
		}

		return Num;
	}

	static string ReadString() {
		string St;

		getline(cin >> ws, St);

		return St;
	}

	static bool IsValidDate(clsDate Date) {
		return clsDate::ValideDate(Date);
	}

};

