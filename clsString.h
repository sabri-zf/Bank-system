#pragma once
#include<iostream>
#include<vector>
using namespace std;
class clsString
{
public:
	string _value;

	void setString(string s1) {
		this->_value = s1;
	}

	string getString() {
		return _value;
	}


	__declspec(property(get = getCharecter, put = setCharacter))char charc1;
	__declspec(property(get = getString, put = setString))string Value;

	static vector<string> splitString(string s1,string delemter = " ") {
		vector<string> VString;
		string word = "";
		short pos = 0;
		while ((pos = s1.find(delemter)) != string::npos) {
			word = s1.substr(0, pos);
			if (word != "") {
				VString.push_back(word);
			}
			s1.erase(0, pos + delemter.length());
		}
		if (s1 != "") {
			VString.push_back(s1);
		}
		return VString;
	}

	vector<string> splitString(string delemter=" ") {
		return splitString(_value,delemter);
	}

	static vector<char> splitCharcter(string s1) {
		vector<char> VString;
		char word;
		short pos = 0;
		short conter = 0;
		while ((pos = s1.find(s1[conter])) != string::npos) {
			word = s1[conter];

			VString.push_back(word);


			s1.erase(0, pos + 1);
		}
		if (s1 != "") {
			VString.push_back(s1[conter]);
		}
		return VString;
	};

	vector<char> splitCharcter() {
		return splitCharcter(_value);
	}

	void FirstLetterforEachWord() {
		vector<string> Vstr1;
		Vstr1 = splitString(_value," ");

		for (int i = 0; i < Vstr1.size(); i++) {
			cout << Vstr1[i][0] << endl;
		}
	}

	static string UpperFirstStringWord(string s1) {
		bool IsFirstLetter = true;

		for (int i = 0; i < LengthOfString(s1); i++) {
			if (s1[i] != ' ' && IsFirstLetter) {
				s1[i] = toupper(s1[i]);
			}

			IsFirstLetter = (s1[i] == ' ') ? true : false;
		}

		return s1;
	}
	string UpperFirstStringWord() {
		return  UpperFirstStringWord(_value);
	}

	static string LowerFirstStringWord(string s1) {
		bool IsFirstLetter = true;

		for (int i = 0; i < LengthOfString(s1); i++) {
			if (s1[i] != ' ' && IsFirstLetter) {
				s1[i] = tolower(s1[i]);
			}

			IsFirstLetter = (s1[i] == ' ') ? true : false;
		}

		return s1;
	}
	string LowerFirstStringWord() {
		return  LowerFirstStringWord(_value);
	}

	static string UpperStringSentence(string s1) {

		for (int i = 0; i < LengthOfString(s1); i++) {
			if (s1[i] != ' ') {
				s1[i] = towupper(s1[i]);
			}
		}

		return s1;
	}
	string UpperStringSentence() {
		return  UpperStringSentence(_value);
	}

	static string LowerStringSentence(string s1) {

		for (int i = 0; i < LengthOfString(s1); i++) {
			if (s1[i] != ' ') {
				s1[i] = tolower(s1[i]);
			}
		}

		return s1;
	}
	string LowerStringSentence() {
		return  LowerStringSentence(_value);
	}

	static char ConvertCharacter(char ch1) {
		return (isupper(ch1)) ? tolower(ch1) : toupper(ch1);
	}

	string convertAllLetterCase(string s1) {
		for (int i = 0; i < s1.length(); i++) {
			s1[i] = ConvertCharacter(s1[i]);
		}
		return s1;
	}
	string convertAllLetterCase() {
		return convertAllLetterCase(_value);
	}

	static int LengthOfString(string s1) {

		vector<char> lengthCharcter;
		lengthCharcter = splitCharcter(s1);

		return lengthCharcter.size();
	}
	int  LengthOfString() {
		return  LengthOfString(_value);
	}

	static int countCapitletterOfString(string s1) {

		int CounterCapitl = 0;
		for (int i = 0; i < LengthOfString(s1); i++) {
			if (isupper(s1[i]) && s1[i] != ' ') {
				CounterCapitl++;
			}


		}

		return CounterCapitl;
	}
	int countCapitletterOfString() {
		return countCapitletterOfString(_value);
	}

	static int countSmilletterOfString(string s1) {

		int CounterSmil = 0;
		for (int i = 0; i < LengthOfString(s1); i++) {
			if ((!isupper(s1[i])) && s1[i] != ' ') {
				CounterSmil++;
			}
		}

		return CounterSmil;
	}
	int countSmilletterOfString() {
		return countSmilletterOfString(_value);
	}

	static int countLetterFromString(string s1, char ch1, bool All_letter = false) {

		int count = 0;

		for (int i = 0; i < LengthOfString(s1); i++) {
			if (!All_letter) {
				if (s1[i] == ch1) {
					count++;
				}
			}
			else {
				if (toupper(s1[i]) == toupper(ch1)) {
					count++;
				}

			}
		}

		return count;
	}
	int countLetterFromString(char ch1, bool All_letter = false) {
		return countLetterFromString(_value, ch1, All_letter);
	}

	static bool IS_vowel(char ch1) {
		return (toupper('a') == toupper(ch1)) || (toupper('e') == toupper(ch1)) || (toupper('i') == toupper(ch1)) || (toupper('o') == toupper(ch1)) || (toupper('u') == toupper(ch1));
	}
	static int CheckVowel(string s1) {
		int count = 0;

		for (int i = 0; i < LengthOfString(s1); i++) {
			if (IS_vowel(s1[i])) {
				count++;
			}
		}
			return count;
	};
	int CheckVowel() {
		return CheckVowel(_value);
	}

	static void PrintVowleValue(string s1) {
		
		short size = LengthOfString(s1);

		for (int i = 0; i < size; i++) {
			if (IS_vowel(s1[i])) {
				cout << s1[i] << "  ";
			}
		}

	}

	void PrintVowleValue() {
		 PrintVowleValue(_value);
	}

	static void CutSentenceToWords(string s1) {
		vector<string> Vword;

		Vword = splitString(s1," ");

		for (int i = 0; i < Vword.size(); i++) {
			cout << Vword[i] << endl;
		}
	}
	void CutSentenceToWords() {
		CutSentenceToWords(_value);
	}

	static int CountSentenceToWord(string s1) {
		vector<string> Vword;

		Vword = splitString(s1," ");

		return Vword.size();
	}
	int CountSentenceToWord() {
		return CountSentenceToWord(_value);
	}

	static string TrimLeftString(string s1) {
		bool IsFirstletter = false;
			while (!IsFirstletter) {

				int i = 0;

				if (s1[i] == ' ') {
					s1.erase(0, i + 1);
					i = 0;
				}
			IsFirstletter = (s1[i] != ' ') ? true : false;
				};
			

		
		return s1;
	}
	string TrimLeftString() {
		return TrimLeftString(_value);
	}

	static string TrimRightString(string s1) {
		int size = LengthOfString(s1);

		for (int i = size - 1; i > 0; i--) {
			if (s1[i] != ' ') {
				return s1.substr(0, i + 1);
			}
		}
		

		return "";
	}

	string TrimRightString() {
		return TrimRightString(_value);
	}

	static string TrimString(string s1) {
		return TrimLeftString(TrimRightString(s1));
	}
	string TrimString() {
		return TrimString(_value);
	}

	static string joinString(vector<string> Vst,string delemter) {
		string word = "";
		for (string& line : Vst) {
			word += line + delemter;
		}

		return word.substr(0, word.length() - delemter.length());
	}
	static string joinString(string arr[], string delemter) {
		int size = arr->length();
		string word = "";
		for (int i = 0; i < size; i++) {
			word += arr[i] + delemter;
		}

		return word.substr(0, word.length() - delemter.length());
	}

	string joinString(string delemter) {
		return joinString(splitString(_value,delemter), delemter);
	}

	static string revirseString(string s1) {
		vector<string> Vrevers;
		Vrevers = splitString(s1," ");

		short size = Vrevers.size();
		s1 = "";
		for (int i = size - 1; i >= 0; i--) {
			s1 += Vrevers[i] + " ";
		}

		return s1.substr(0, s1.length() - 1);
	}
	string revirseString() {
		return revirseString(_value);
	}

	static string replaceString(string s1, string current, string Now, string delmet = " ", bool MatchCace = false) {
		vector<string> Vstring;
		Vstring = splitString(s1, delmet);

		s1 = "";
		if(!MatchCace)
		for (string& Val : Vstring) {

			if (Val == current) {
				Val = Now;
			}
			s1 += Val + delmet;
		}
		else
			for (string& Val : Vstring) {

				if (UpperStringSentence(Val) == UpperStringSentence(current)) {
					Val = Now;
				}
				s1 += Val + " ";
			}

		return s1.substr(0, s1.length() - 1);
	}
	string replaceString(string current, string Now, string delmet = " ",bool Matchcase = false) {
		return  replaceString(_value, current,Now, delmet,Matchcase);
	}

	static bool IsPunctuations(char ch1) {

		char spriterPunc[33] = { 33,34,35,36,37,38,39,40,41,42,43,44,45,46,47
		,58,59,60,61,62,63,64,91,92,93,94,95,96,123,124,125,126 };

		for (int i = 0; i < 33; i++) {
			if (ch1 == char(spriterPunc[i])) {
				return true;
			}
		}

		return false;
	}

	static string RemoveAllPunctuations(string s1) {
		int size = LengthOfString(s1);

		for (int i = 0; i < size; i++) {
			if (IsPunctuations(s1[i])) {
				s1[i] = 0;
			}
		}

		return s1;
	}
	string RemoveAllPunctuations() {
		return RemoveAllPunctuations(_value);
	}

};