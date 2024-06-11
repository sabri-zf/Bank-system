#pragma once
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
class clsUlit
{
public:

	static string encryptText(string text) {
		for (int i = 0; i < text.length(); i++) {
			text[i] = char(text[i] + 2);
		}

		return text;
	}
	static string deCryptText(string text) {
		for (int i = 0; i < text.length(); i++) {
			text[i] = char(text[i] - 2);
		}

		return text;
	}

	static void Srand() {
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To) {
		int randNum = rand() % (To - (From + 1)) + From;

		return randNum;
	}

	enum TypeValue { _small = 1, _capital = 2, _specailCh = 3,_digit=4,_Mix=5 };

	static char GetRandomCharacter(TypeValue value) {
		switch (value)
		{
		case clsUlit::_small:
			return RandomNumber(97, 122);
			break;
		case clsUlit::_capital:
			return RandomNumber(65,90);
			break;
		case clsUlit::_specailCh:
			return RandomNumber(33,47);
			break;
		case clsUlit::_digit:
			return RandomNumber(48, 57);
			break;
		case clsUlit::_Mix:
			return RandomNumber(33, 126);
			break;
		}
	}

	static string GenerateKey() {
		string key="";

		for (int i = 0; i < 4; i++) {

			string  word = "";

			for (int i = 0; i < 4; i++) {
				word += char(GetRandomCharacter(clsUlit::_capital));
			}

			key += word + "-";
		}
		
		return key.substr(0, key.length() - 1);
	}

	static void fillArrayWithRandomNumber(int arr[],int sizeOfArray,int From,int To) {
		for (int i = 0; i < sizeOfArray; i++) {
			arr[i] = RandomNumber(From, To);
		}
	}
	static void fillArrayWithRandomKey(string arr[],int sizeOfArray) {
		for (int i = 0; i < sizeOfArray; i++) {
			arr[i] = GenerateKey();
		}
	}

	static void _Swap(int& A, int& B) {
		int temp;
		temp = A;
		A = B;
		B = temp;
	}
	static void _Swap(short& A, short& B) {
		short temp;
		temp = A;
		A = B;
		B = temp;
	}
	
	static void _Swap(double& A, double& B) {
		double temp;
		temp = A;
		A = B;
		B = temp;
	}
	static void _Swap(float& A, float& B) {
		float temp;
		temp = A;
		A = B;
		B = temp;
	}

	static void _Swap(bool& A, bool& B) {
		bool temp;
		temp = A;
		A = B;
		B = temp;
	}

	static void ShuffleArray(int arr[], int sizeOfArray) {

		for (int i = 0; i < sizeOfArray; i++) {
			_Swap(arr[RandomNumber(1,sizeOfArray)-1], arr[RandomNumber(1, sizeOfArray) - 1]);
		}
	}

	static string Taps(short size) {
		string tap = "	";
		for (int i = 0; i < size; i++) {
			tap += tap;
		}

		return tap;
	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	};
	





};

