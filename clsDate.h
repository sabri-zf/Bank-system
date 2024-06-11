#pragma warning(disable : 4996) ;

#pragma once

#include<iostream>
#include<vector>
#include"clsString.h"
#include<string>
using namespace std;

class clsDate
{
private:
	 short _Day, _Month, _Year;
	  short _Hour, _minute, _second;

	void PushInformationOfDate(string _date) {
		vector<string> Vdate;
		Vdate = clsString::splitString(_date, "/");

		_Day = stoi(Vdate[0]);
		_Month = stoi(Vdate[1]);
		_Year = stoi(Vdate[2]);
	}
public:

 clsDate DateNow() {
		time_t t = time(0);
		tm* now = localtime(&t);
		this->_Day = now->tm_mday;
		this->_Month = now->tm_mon + 1;
		this->_Year = now->tm_year + 1900;
		this->_Hour = now->tm_hour;
		this->_minute = now->tm_min;
		this->_second = now->tm_sec;

		return clsDate(this->_Day, this->_Month, this->_Year,_Hour,_minute,_second);
	}


	void SetDay(short day) {
		_Day = day;
	}
	short GetDay() {
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay))short day;


	void SetMonth(short month) {
		_Month = month;
	}
	short GetMonth() {
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth))short month;


	void setYear(short year) {
		_Year = year;
	}
	short GetYear() {
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear))short year;

	
	// adding counstructer 
	clsDate() {
		*this = DateNow();
	}
	clsDate(string Date) {
		PushInformationOfDate(Date);
	}
	clsDate(short day, short month, short year,short Hour=0,short minute=0,short second=0) {
		_Day = day;
		_Month = month;
		_Year = year;
		_Hour = Hour;
		_minute = minute;
		_second = second;
 	}

	//===============================================

	static void _swapDate(clsDate &Date1,clsDate &Date2) {
		clsDate DateTemp;
		DateTemp = Date1;
		Date1 = Date2;
		Date2 = DateTemp;
	}

	static bool IsLeapYear(int year) {
		return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
	}
	bool IsLeapYear() {
		return IsLeapYear(_Year);
	}
	
	static short NumberOfDay(short year) {
		return IsLeapYear(year) ? 366 : 365;
	}
	short NumberOfDay() {
		return NumberOfDay(_Year);
	}

	static int NumberOfHour(short day) {
		return (day * 24);
	}
	int NumberOfHour() {
		return  NumberOfHour(NumberOfDay());
	}

	static int NumberOfMinute(int hour) {
		return (hour * 60);
	}
	int NumberOfMinute() {
		return NumberOfMinute(NumberOfHour());
	}

	static int NumberOfSecond(int minute) {
		return (minute * 60);
	}
	int NumberOfSecond() {
		return NumberOfSecond(NumberOfMinute());
	}
	
	static short DayInMonth(short year, short month) {
		if (month < 0 || month > 12)
			return 0;
		short Day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : Day[month - 1];
	}
	short DayInMonth() {
		return DayInMonth(_Year,_Month);
	}

	static int HourInMonth(short day) {
		return (day * 24);
	}
	int HourInMonth() {
		return  HourInMonth(DayInMonth());
	}

	static int MinuteInMonth(int hour) {
		return (hour * 60);
	}
	int MinuteInMonth() {
		return NumberOfMinute(HourInMonth());
	}

	static int SecondInMonth(int minute) {
		return (minute * 60);
	}
	int SecondInMonth() {
		return SecondInMonth(MinuteInMonth());
	}

	static short OrderDayOfWeek(clsDate d1,bool MatchCase = false) {
		short a, y, m;
		a = (14 - d1._Month) / 12;
		y = d1._Year - a;
		m = d1._Month + (12 * a) - 2;

		if (MatchCase) {
			d1._Day = 1;
		}

		return (d1._Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short OrderDayOfWeek(bool MatchCase = false) {
		return OrderDayOfWeek(*this, MatchCase);
	}

	static string NameDayOfWeek(short orderDay) {
		if (orderDay < 0 || orderDay > 6) {
			return "Pleses Enter Number Between [0-6] \n";
		}
		string NameDay[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return NameDay[orderDay];
	}
	string NameDayOfWeek() {
		return NameDayOfWeek(OrderDayOfWeek());
	}

	//+++++++++++++++++++++++++
	void MonthClender() {
		string arrOfNameMonth[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

		short days = DayInMonth();
		short dayOrders = OrderDayOfWeek(true);

		cout << "\n___________________ " << arrOfNameMonth[_Month - 1] << " _______________\n\n";
		printf("  Sun  Mon  Tus  Wed  Thu  Fri  Sat\n");
		int i = 0;
		for (; i < dayOrders; i++) {
			printf("     ");
		}

		for (int j = 1; j <= days; j++) {
			printf("%5d", j);

			if (++i == 7) {
				i = 0;
				cout << "\n";
			}
		}

		cout << "\n_______________________________________\n";


	}

	void YearClender() {
		_Month = 1;
		for (int i = 0; i < 12; i++) {
			MonthClender();
			_Month++;
		}
	}

	static short TotalDayFromBegnningYear(short day, short month, short year) {
		short dayOfBigYear = 0;

		for (int i = 1; i <= month - 1; i++) {
			dayOfBigYear += DayInMonth(year, i);
		}
		dayOfBigYear += day;

		return dayOfBigYear;
	}
	short TotalDayFromBegnningYear() {
		return TotalDayFromBegnningYear(_Day, _Month, _Year);
	}

	static clsDate ReversTotalDayFromBigging(clsDate Date,short DayRemander, short AddMoreDay = 0) {
		short RemandetDate = DayRemander + AddMoreDay;
		Date._Month = 1;
		while (true)
		{
			short DayMon = DayInMonth(Date._Year, Date._Month);
			if (DayMon < RemandetDate) {
				RemandetDate -= DayMon;
				Date._Month++;
				if (Date._Month > 12) {
					Date._Year++;
					Date._Month = 1;
				}
			}
			else {
				Date._Day = RemandetDate;
				break;
			}
		}

		return clsDate(Date._Day, Date._Month, Date._Year);
	}
	 void ReversTotalDayFromBigging(short AddMoreDay = 0) {
		 *this =   ReversTotalDayFromBigging(*this,TotalDayFromBegnningYear(), AddMoreDay);
	 }

	 static bool IsDateOneBeforDateTwo(clsDate Date,clsDate Date2) {
		 return (Date._Year < Date2._Year) ? true : ((Date._Year == Date2._Year) ? (Date._Month < Date2._Month) ? true : ((Date._Month == Date2._Month) ? (Date._Day < Date2._Day) ? true : ((Date._Day == Date2._Day) ? true : false): false) : false);
	 }
	 bool IsDateOneBeforDateTwo(clsDate Date2) {
		 return IsDateOneBeforDateTwo(*this, Date2);
	}

	static bool IsDateOneEqualDateTwo(clsDate Date, clsDate Date2) {
		 return (Date._Year == Date2._Year) ? ((Date._Month == Date2._Month) ? (Date._Day == Date2._Day):false) : false;
	 }
	bool IsDateOneEqualDateTwo(clsDate Date2) {
		return IsDateOneEqualDateTwo(*this, Date2);
	}

	static bool IsDateOneAfterDateTwo(clsDate Date1, clsDate Date2) {
		return (!IsDateOneBeforDateTwo(Date1,Date2)) && (!IsDateOneEqualDateTwo(Date1,Date2));
	}
	bool IsDateOneAfterDateTwo(clsDate Date2) {
		return IsDateOneAfterDateTwo(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate date) {
		return (date._Day == DayInMonth(date._Year, date._Month));
	}
	bool IsLastDayInMonth() {
		return IsLastDayInMonth(*this);
	}

	static 	bool IslastMonthInYear(clsDate date) {
		return (date._Month == 12);
	}
	        bool IslastMonthInYear() {
		return IslastMonthInYear(*this);
	}

	static clsDate IncreaseDateByOneDay(clsDate Date) {
		if (IsLastDayInMonth(Date)) {
			if(IslastMonthInYear(Date)){
				Date._Year++;
				Date._Month = 1;
				Date._Day = 1;
			}

			Date._Month ++;
			Date._Day = 1;
		}
		else {
			Date._Day++;
		}

		return Date;
	}
	void IncreaseDateByOneDay() {
		*this = IncreaseDateByOneDay(*this);
	}

	static clsDate IncreaseMoreDay(clsDate date,short days) {
		for (int i = 0; i < days; i++) {

			date = IncreaseDateByOneDay(date);
		}

		return date;
	}
	void IncreaseMoreDay(short days) {
		*this = IncreaseMoreDay(*this, days);
	}

	static clsDate IncreaseMoreWeek(clsDate &date, short Weeks) {
		short week = 7 * Weeks;
		for (int i = 0; i < week; i++) {

			date = IncreaseDateByOneDay(date);
		}

		return date;
	}
	void IncreaseMoreWeek(short weeks) {
		*this = IncreaseMoreWeek(*this, weeks);
	}

	static clsDate IncreaseOneMonth(clsDate& Date) {
		if (Date._Month == 12) {

			Date._Month = 1;
			Date._Year++;

		}
		else {
			Date._Month++;
		}

		short DayOfMon = DayInMonth(Date._Year, Date._Month);
		if (Date._Day > DayOfMon) {
			Date._Day = DayOfMon;
		}

		return Date;
	}
	void IncreaseOneMonth() {
		*this = IncreaseOneMonth(*this);
	}

	static clsDate IncreaseMoreMonth(clsDate Date, short AmountMonth = 1) {
		for (int i = 0; i < AmountMonth; i++) {
			Date = IncreaseOneMonth(Date);
		}

		return Date;
	}
	void IncreaseMoreMonth(short AmountMonth = 1) {
		*this = IncreaseMoreMonth(*this, AmountMonth);
	}

	static clsDate IncreaseOneYear(clsDate Date) {
		Date._Year++;

		return Date;
	}
	void IncreaseOneYear() {
		*this = IncreaseOneYear(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate Date) {
		if (Date._Day == 1) {
			if (Date._Month == 1) {
				Date._Month = 12;
				Date._Day = 31;
				Date._Year--;
			}
			Date._Month--;
			Date._Day = DayInMonth(Date._Year, Date._Month);
		}
		else {
			Date._Day--;
		}
		return Date;
	}
	void DecreaseDateByOneDay() {
		*this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseMoreDay(clsDate Date, short Days) {
		for (int i = 0; i < Days; i++) {
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseMoreDay(short Days) {
		*this = DecreaseMoreDay(*this,Days);
	}

	static clsDate DecreaseOneMonth(clsDate Date) {
		if (Date._Month == 1) {
			Date._Month = 12;
			Date._Year--;
		}
		else {
			Date._Month--;
		}

		short DayMon = DayInMonth(Date._Year, Date._Month);

		if (Date._Day > DayMon) {
			Date._Day = DayMon;
		}

		return Date;
	}
	void DecreaseOneMonth() {
		*this = DecreaseOneMonth(*this);
	}

	static clsDate DecreaseMoreMonths(clsDate Date, short Months) {
		for (int i = 0; i < Months; i++) {
			Date = DecreaseOneMonth(Date);
		}

		return Date;
	}
	void DecreaseMoreMonths(short Months) {
		*this = DecreaseMoreMonths(*this, Months);
	}

	static clsDate DecraseOneYear(clsDate Date) {
		Date._Year--;

		return Date;
	}
	void DecraseOneYear() {
		*this = DecraseOneYear(*this);
	}

	static bool IsEndOfWeek(clsDate Date) {
		short OrderDay = OrderDayOfWeek(Date);

		if (OrderDay == 6) {
			return true;
		}

		return false;
	}
	bool IsEndOfWeek() {
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date) {
		short OrderDay = OrderDayOfWeek(Date);

		if ((OrderDay == 5) || (OrderDay == 6)) {
			return true;
		}

		return false;
	}
	bool IsWeekEnd() {
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date) {
		if (!IsWeekEnd(Date)) {
			return true;
		}

		return false;
	}
	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	}

	static short DaysUntilEndOfweek(clsDate Date) {
		short OrderDay = OrderDayOfWeek(Date);

		return (6 - OrderDay);
	}
	short DaysUntilEndOfweek() {
		return DaysUntilEndOfweek(*this);
	}

	static short DaysUntilEndOfMonth(clsDate Date) {
		clsDate Date1(DayInMonth(Date._Year, Date._Month), Date._Month, Date._Year);

		return DiffrenceDay(Date, Date1,true);
	}
	short DaysUntilEndOfMonth() {
		return DaysUntilEndOfMonth(*this);
	}

	static short DayUntilEndOfYear(clsDate Date) {
		clsDate Date1(31, 12, Date._Year);

		return DiffrenceDay(Date, Date1,true);
	}
	short DayUntilEndOfYear() {
		return DayUntilEndOfYear(*this);
	}

	static short VacationDay(clsDate Date1,clsDate Date2,bool IncludeEndDay=false){
		short counter = 0;

		while (IsDateOneBeforDateTwo(Date1, Date2)) {
			if (IsBusinessDay(Date1)) {
			counter++;
			}
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IncludeEndDay?++counter:counter;
	}
	short VacationDay(clsDate Date2, bool IncludeEndDay = false) {
		return VacationDay(*this, Date2,IncludeEndDay);
	}

	static clsDate DateOfEndVacationDay(clsDate Date,short DayVacation) {
		short countWeekEnd = 0;
		for (int i = 0; i < DayVacation; i++) {
			if (IsWeekEnd(Date)) {
				countWeekEnd++;
			}
			Date = IncreaseDateByOneDay(Date);
		}

		for (int i = 0; i < countWeekEnd; i++) {
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}
	void DateOfEndVacationDay(short DayVacation) {
		*this = DateOfEndVacationDay(*this, DayVacation);
	}

  static short DiffrenceDay(clsDate Date1, clsDate Date2,bool IncludingEndDay=false) {
		short counter = 0;

		while ((IsDateOneBeforDateTwo(Date1, Date2))) {
			counter++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IncludingEndDay ? ++counter : counter;
	}
         short DiffrenceDay(clsDate Date2, bool IncludingEndDay = false) {
	        return DiffrenceDay(*this, Date2,IncludingEndDay);
		 }

		 static short CalcAgeByDay(clsDate DateBirth, clsDate Datenow) {
			 return DiffrenceDay(DateBirth, Datenow);
		 }
		 int CalcAgeByDay(clsDate DateBirth) {
			 return DiffrenceDay(DateBirth,*this);
		 }

	static bool ValideDate(clsDate Date) {
		if (Date._Year <= 0 || Date._Year < 1970) {
			return false;
		}

		return ((Date._Day > 0) && (Date._Day <= DayInMonth(Date._Year, Date._Month)));
	}
	bool ValideDate() {
		return ValideDate(*this);
	}
	short PriodLength(clsDate Date1, clsDate Date2, bool IncludingEndDay = false) {
		return VacationDay(Date1, Date2, IncludingEndDay);
	}

	static string formatingDate(clsDate Date, string Format, string Delmet) {
		string DateWord = "";
		DateWord = clsString::replaceString(Format, "dd", to_string(Date._Day), Delmet);
		DateWord = clsString::replaceString(DateWord, "mm", to_string(Date._Month), Delmet);
		DateWord = clsString::replaceString(DateWord, "yyyy", to_string(Date._Year), Delmet);

		return DateWord;
	}
	string formatingDate(string Format, string Delmet) {
		return formatingDate(*this, Format, Delmet);
	}
	
	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDateOneBeforDateTwo(Date1, Date2))
			return enDateCompare::Before;

		if (IsDateOneEqualDateTwo(Date1, Date2))
			return enDateCompare::Equal;

		/* if (IsDate1AfterDate2(Date1,Date2))
			 return enDateCompare::After;*/

			 //this is faster
		return enDateCompare::After;

	}

	static string DateToString(clsDate Date) {
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}
	string DateToString() {
		return DateToString(*this);
	}

	static string TimeToString(clsDate Date) {
		return to_string(Date._Hour) + ":" + to_string(Date._minute) + ":" + to_string(Date._second);
	}

	string TimeToString() {
		return TimeToString(*this);
	}
	 

	 void Print() {
		cout <<NameDayOfWeek()<<", " << _Day << "/" << _Month << "/" << _Year << endl;
	}
	
};

