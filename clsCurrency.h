#pragma once
#include<iostream>
#include"clsString.h"
#include<string>
#include<vector>
#include<fstream>

class clsCurrency
{
private:
	enum eMode { eEmptyMode = 1, eUpdateMode = 2 };
	eMode _typeMode;
	string _country;
	string _currencyCode;
	string _currencyName;
	double _rate;
	static clsCurrency _EmptyCurrency() {
		return clsCurrency(eEmptyMode, "", "", "", 0);
	}
	static clsCurrency _convertCurrencyToObject(string line, string sepriter="#//#") {
		vector<string> Vcurrency;
		Vcurrency = clsString::splitString(line, sepriter);

		return clsCurrency(eUpdateMode, Vcurrency[0], Vcurrency[1], Vcurrency[2], stod(Vcurrency[3]));
	}
	static string convertObjectToLine(clsCurrency curr, string sepriter = "#//#") {
		string word = "";

		word += curr._country + sepriter;
		word += curr._currencyCode+ sepriter;
		word += curr._currencyName+ sepriter;
		word += to_string(curr._rate);

		return word;
	}
	static vector<clsCurrency> _loadCurrencyDataFromFile() {
		fstream ReadData;
		vector < clsCurrency > Vcurre;
		ReadData.open("Currencies.txt", ios::in);
		if (ReadData.is_open()) {
			string line = "";
			while (getline(ReadData, line)) {
				if (line != "") {
					clsCurrency curre = _convertCurrencyToObject(line);
					Vcurre.push_back(curre);
				}
			}
			ReadData.close();
		}
			return Vcurre;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency> curre) {
		fstream SaveData;
		SaveData.open("Currencies.txt", ios::out);
		if (SaveData.is_open()) {
			string line = "";
			for (clsCurrency& Cu : curre) {
				line = convertObjectToLine(Cu);
				SaveData << line << endl;
			}
			SaveData.close();
		}
	}
	 void _Update() {
		vector<clsCurrency> Vcurre = _loadCurrencyDataFromFile();

		for (clsCurrency& Cu : Vcurre) {
			if (Cu.GetCurrencCode() == GetCurrencCode()) {
				Cu = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(Vcurre);
	}


public:
	clsCurrency(eMode mode, string country, string CurrCode, string CurrName, double rate) {
		_typeMode = mode;
		_country = country;
		_currencyCode = CurrCode;
		_currencyName = CurrName;
		_rate = rate;
	}
	string GetCountry() {
		return _country;
	}
	string GetCurrencCode() {
		return _currencyCode;
	}
	string GetCurrencName() {
		return _currencyName;
	}
	double GetRate() {
		return _rate;
	}

	 void UpdateRate(double rateVal) {
		_rate = rateVal;
		_Update();
	}

	bool IsEmpty() {
		return (_typeMode == eEmptyMode);
	}

	static clsCurrency FindByCode(string Code) {
		 string UpperCode = clsString::UpperStringSentence(Code);
		vector<clsCurrency> Vcurre = _loadCurrencyDataFromFile();

		for (clsCurrency& Cu : Vcurre) {
			if (Cu.GetCurrencCode() == UpperCode) {
				return Cu;
			}
		}

		return _EmptyCurrency();
	} 
	static clsCurrency FindByCountry(string country) {
		vector<clsCurrency> Vcurre = _loadCurrencyDataFromFile();

		for (clsCurrency& Cu : Vcurre) {
			if (clsString::UpperStringSentence(Cu.GetCountry()) == clsString::UpperStringSentence(country)) {
				return Cu;
			}
		}

		return _EmptyCurrency();
	}
	
	static bool IscurrencyExist(string Find,bool MatchCountry = false) {
		if (MatchCountry) {
			clsCurrency curre = clsCurrency::FindByCountry(Find);
			return (!curre.IsEmpty());
		}
		else {
		clsCurrency curre = clsCurrency::FindByCode(Find);
		return (!curre.IsEmpty());
		}
	}
	 
	static vector<clsCurrency> GetcurrencyList() {
		return _loadCurrencyDataFromFile();
	}
};


