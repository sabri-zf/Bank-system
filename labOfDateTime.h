#pragma once
#include <iostream>
#include<vector>
#include<string>
using namespace std;

namespace dateTime {
	struct Sdate
	{
		short year;
		short month;
		short day;
	};
	struct FullDa {
		Sdate DateStart;
		Sdate DateEnd;

	};
	short readNumber(string message) {
		short num;
		cout << message;
		cin >> num;
		return num;
	}
	int numberofyear() {
		short num;
		cout << "\npleaes enter Year  : ";
		cin >> num;

		return num;
	}
	int numberofMonth() {
		int month;
		cout << "\nPlase enter Month : ";
		cin >> month;
		return month;
	}
	int numberofday() {
		int day;
		cout << "Plase enter day : ";
		cin >> day;
		return day;
	}
	Sdate readFullDate() {
		Sdate date;
		date.day = numberofday();
		date.month = numberofMonth();
		date.year = numberofyear();

		return date;

	}

	FullDa readAlldate(Sdate dS, Sdate dE) {
		FullDa Date;

		Date.DateStart = dS;
		Date.DateEnd = dE;

		return Date;
	}


	// order day 

	short dayOrderOfWeek(Sdate d1,bool MatchCase = false) {
		short a, y, m;
		a = (14 - d1.month) / 12;
		y = d1.year - a;
		m = d1.month + (12 * a) - 2;

		if (MatchCase) {
			d1.day = 1;
		}

		return (d1.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short dayOrder(Sdate d1,bool day) {
		return dayOrderOfWeek(d1, day);
	}

	// the check bout year is leap or not 
	bool IsLeapYear(int year) {
		return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
	}
// this is founction of get day of month 
	int dayOfMonth(int year, int month) {
		if (month < 1 || month>12)
			return 0;

		int arrOfdayMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrOfdayMonth[month - 1];
	}

	// calender of month 
	void MonthClender(Sdate Date) {
		string arrOfNameMonth[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

		short days = dayOfMonth(Date.year,Date.month);
		short dayOrders = dayOrder(Date,true);

		cout << "\n___________________ " << arrOfNameMonth[Date.month - 1] << " __________________\n\n";
		printf("   Sat  Sun  Mon  Tus  Wed  Thu  Fri\n");
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
	//claculter day from year 
	short totalDayfromBegnningYear(short year, short month, short day) {
		short dayOfBigYear = 0;

		for (int i = 1; i <= month - 1; i++) {
			dayOfBigYear += dayOfMonth(year, i);
		}
		dayOfBigYear += day;

		return dayOfBigYear;
	}
	// adding more day
	int howManyToNeedaddingDay(string message) {
		int daysAdd;
		cout << "\n" << message;
		cin >> daysAdd;

		return daysAdd;
	}
	//return date back oroginal
	Sdate convertTheBackDate(Sdate date, int addDays) {
		Sdate newDate;

		int day = totalDayfromBegnningYear(date.year, date.month, date.day) + addDays;

		newDate.year = date.year;
		newDate.month = 1;

		while (true) {
			short dayOfMon = dayOfMonth(newDate.year, newDate.month);

			if (day > dayOfMon) {
				day -= dayOfMon;
				newDate.month++;

				if (newDate.month > 12) {
					newDate.year++;
					newDate.month = 1;
				}
			}
			else {
				newDate.day = day;
				break;
			}
		}

		return newDate;

	}
	// check if date equal date
	bool IsDate1EqualDate2(Sdate d1, Sdate d2) {
		return (d1.year == d2.year) && (d1.month == d2.month) && (d1.day == d2.day);
	}
    // check if date 1 lasse than date 2
	bool IsDate1BeforDate2(Sdate d1, Sdate d2) {
		return (d1.year < d2.year) ? true : ((d1.year == d2.year) ? (d1.month < d2.month) ? true : ((d1.month == d2.month) ? (d1.day < d2.day) : false) : false);
	}
	// check date one after date two
	bool IsDateOneAfterDateTwo(Sdate d1, Sdate d2) {
		return (!IsDate1BeforDate2(d1, d2) && !IsDate1EqualDate2(d1, d2));
	}

	//---------------------
	short daysOfYear(Sdate date, short plusoneYear = 0) {
		return IsLeapYear(date.year - plusoneYear) ? 366 : 365;
	}

	short diffOfYearBetwinTwoDate(Sdate d1, Sdate d2, short totalDaysOfDate2) {
		short diff = d2.year - d1.year, days = 0;
		if (diff == 0) {
			return totalDaysOfDate2;
		}

		for (int i = 1; i <= diff; i++) {
			days += daysOfYear(d2, i);
		}
		days += totalDaysOfDate2;

		return days;
	}

	bool IsDate1LessThenDate2(Sdate d1, Sdate d2) {
		short dayOfDate1 = 0, DayOfDate2 = 0;
		DayOfDate2 = totalDayfromBegnningYear(d2.year, d2.month, d2.day);
		dayOfDate1 = totalDayfromBegnningYear(d1.year, d1.month, d1.day);

		if (d1.year == d2.year) {
			return dayOfDate1 < DayOfDate2;
		}

		return dayOfDate1 < diffOfYearBetwinTwoDate(d1, d2, DayOfDate2);
	}

	// check last day and month
	bool IsLastDayInMonth(Sdate date) {
		return (date.day == dayOfMonth(date.year, date.month));
	}
	bool IslastMonthInYear(Sdate date) {
		return (date.month == 12);
	}

	// increaes date by one day 
	Sdate IncreaseDateByOneDay(Sdate d1,short day=1) {
		return convertTheBackDate(d1, day);
	}
	// trice of swip date becuse we con not clac date less than date 
	void swipDate(Sdate& d1, Sdate& d2) {
		Sdate Tempdate;

		Tempdate.day = d1.day;
		Tempdate.month = d1.month;
		Tempdate.year = d1.year;

		d1.day = d2.day;
		d1.month = d2.month;
		d1.year = d2.year;

		d2.day = Tempdate.day;
		d2.month = Tempdate.month;
		d2.year = Tempdate.year;

	}

	// clculeter diffrence day or calc birth day 
	short diffrenceDay(Sdate d1, Sdate d2, bool IncludingCase = false) {

		short convertResult = 1;
		if (!IsDate1BeforDate2(d1, d2)) {
			swipDate(d1, d2);
			convertResult = -1;
		}

		if (IsDate1BeforDate2(d1, d2)) {

			short dateOne = totalDayfromBegnningYear(d1.year, d1.month, d1.day);
			short dateTwo = diffOfYearBetwinTwoDate(d1, d2, totalDayfromBegnningYear(d2.year, d2.month, d2.day));

			short result = dateTwo - dateOne;

			return IncludingCase ? ++result * convertResult : result*convertResult;
		}
		

		

		return 0;
	}

	// time now
	Sdate timeNow() {
		Sdate timeOfnow;

		time_t t = time(0);
		tm* now = localtime(&t);
		timeOfnow.year = now->tm_year + 1900;
		timeOfnow.month = now->tm_mon + 1;
		timeOfnow.day = now->tm_mday;

		return timeOfnow;
	}

	// increase by one day 
	Sdate addingMoreDay(Sdate d1, short days) {
		return IncreaseDateByOneDay(d1, days);
	}
	Sdate addingWeek(Sdate d1) {
		d1 = addingMoreDay(d1, 7);
		return d1;
	}
	Sdate addingMoreWeeks(Sdate d1, short week) {

		for (int i = 1; i <= week; i++) {
			d1 = addingWeek(d1);
		}



		return d1;
	}
	Sdate addingOneMonth(Sdate d1) {

		if (d1.month == 12) {
			d1.year++;
			d1.month = 1;
		}
		else {
			d1.month++;
		}

		short dayOfM = dayOfMonth(d1.year, d1.month);

		if (dayOfM < d1.day) {
			d1.day = dayOfM;
		}

		return d1;
	}
	Sdate addingMoreMonth(Sdate d1, short Months) {
		for (int i = 1; i <= Months; i++) {
			d1 = addingOneMonth(d1);
		}

		return d1;
	}
	Sdate addingOneYear(Sdate d1) {
		d1.year++;
		return d1;
	}
	Sdate addingMoreYear(Sdate d1, short years) {
		for (int i = 1; i <= years; i++) {
			d1 = addingOneYear(d1);
		}

		return d1;
	}
	Sdate addingMoreYear$Faster$(Sdate d1, short years) {
		d1.year += years;

		return d1;
	}
	Sdate addingOneDecate(Sdate d1) {
		d1.year += 10;

		return d1;
	}
	Sdate addingMoreDecate(Sdate d1, short Decates) {
		for (int i = 1; i <= Decates; i++) {
			d1 = addingOneDecate(d1);
		}

		return d1;
	}
	Sdate addingMoreDecate$Faster$(Sdate d1, short Decates) {
		d1.year += 10 * Decates;
		return d1;
	}
	Sdate addingCentruy(Sdate d1) {
		d1.year += 100;
		return d1;
	}
	Sdate addingMilleniun(Sdate d1) {
		d1.year += 1000;
		return d1;
	}

	// decrease by one day 


	Sdate deincreaseByOneDay(Sdate d1) {
		if (d1.day == 1) {
			if (d1.month == 1) {
				d1.year--;
				d1.month = 12;
				d1.day = 31;
			}
			else {
				d1.month--;
				d1.day = dayOfMonth(d1.year, d1.month);
			}
		}
		else {
			d1.day--;
		}
		return d1;
	}
	Sdate deleteDayMoreDate(Sdate d1, short day) {
		for (int i = 1; i <= day; i++) {
			d1 = deincreaseByOneDay(d1);
		}

		return d1;
	}
	Sdate DeleteDayByOneWeek(Sdate d1) {

		d1 = deleteDayMoreDate(d1, 7);

		return d1;
	}
	Sdate DeleteDayByMoreWeeks(Sdate d1, short week) {
		for (int i = 1; i <= week; i++) {
			d1 = DeleteDayByOneWeek(d1);
		}

		return d1;
	}
	Sdate DeleteDayByOneMonth(Sdate d1) {
		if (d1.month == 1) {
			d1.year--;
			d1.month = 12;
		}
		else {
			d1.month--;
		}

		short DayDiff = dayOfMonth(d1.year, d1.month);

		if (DayDiff < d1.day) {
			d1.day = DayDiff;
		}

		return d1;
	}
	Sdate DeletDayByMoreMonth(Sdate d1, short Mon_s) {

		for (int i = 1; i <= Mon_s; i++) {
			d1 = DeleteDayByOneMonth(d1);
		}

		return d1;
	}
	Sdate DeleteoneYear(Sdate d1) {
		d1.year--;
		return d1;
	}
	Sdate DeletMoreYear(Sdate d1, short year) {
		for (int i = 1; i <= year; i++) {
			d1 = DeleteoneYear(d1);
		}
		return d1;
	}
	Sdate DeletMoreYear$faster$(Sdate d1, short year) {
		d1.year -= year;

		return d1;
	}
	Sdate DeletOneDecate(Sdate d1) {
		d1.year -= 10;

		return d1;
	}
	Sdate DeletMoreDecate(Sdate d1, short Deca) {
		for (int i = 1; i <= Deca; i++) {
			d1 = DeletOneDecate(d1);
		}

		return d1;
	}
	Sdate DeletMoreDecate$faster$(Sdate d1, short Deca) {
		d1.year -= Deca * 10;
		return d1;
	}
	Sdate DeleteOneCuntry(Sdate d1) {
		d1.year -= 100;

		return d1;
	}
	Sdate DeleteoneMillenue(Sdate d1) {
		d1.year -= 1000;

		return d1;
	}

	// information about date 
	string WriteInfoOfDate(Sdate d1) {
		short order = dayOrderOfWeek(d1);

		string arrOfNameDayOfweek[] = { "Sun","Mon","Tue","Wed","The","Fri","Sat" };

		return arrOfNameDayOfweek[order];

	}

	bool IsEndOfWeek(Sdate d1) {
		short order = dayOrderOfWeek(d1);

		return order == 6;
	}

	bool IsWeekEnd(Sdate d1) {
		short order = dayOrderOfWeek(d1);

		return order == 5 || order == 6;
	}

	bool isBussinessDay(Sdate d1) {
		return !IsWeekEnd(d1);
	}

	short DayUntilOfEndWeek(Sdate d1) {
		short order = dayOrderOfWeek(d1);

		return 6 - order;
	}
	short DayUnitlOfEndMonth(Sdate d1) {
		Sdate endM;

		endM.day = dayOfMonth(d1.year, d1.month);
		endM.month = d1.month;
		endM.year = d1.year;

		return diffrenceDay(d1, endM, true);
	}
	short DayUnitlOfEndyear(Sdate d1) {
		Sdate endY;
		endY.day = 31;
		endY.month = 12;
		endY.year = d1.year;

		return diffrenceDay(d1, endY, true);
	}

	// vacition the job
	short VecatitonDays(Sdate d1, Sdate d2) {
		short count = 0;

		while (IsDate1BeforDate2(d1, d2)) {
			if (isBussinessDay(d1)) {
				count++;
			}
			d1 = IncreaseDateByOneDay(d1);
		}

		return count;
	}

	Sdate returnVacitionToDate(Sdate d1, short Veca_Day) {
		short day = 0;

		for (int i = 1; i <= Veca_Day; i++) {
			if (IsWeekEnd(d1))
			{
				day++;
			}
			d1 = IncreaseDateByOneDay(d1);
		}

		for (int i = 1; i <= day; i++) {
			d1 = IncreaseDateByOneDay(d1);
		}

		return d1;
	}


	// compare date 
	enum checkChooes { befor = -1, equal = 0, after = 1 };

	checkChooes compareDate(Sdate d1, Sdate d2) {
		if (IsDate1BeforDate2(d1, d2) && !IsDate1EqualDate2(d1, d2)) {
			return checkChooes::befor;
		}
		else if (IsDateOneAfterDateTwo(d1, d2) && !IsDate1EqualDate2(d1, d2)) {
			return checkChooes::after;
		}

		return checkChooes::equal;
	}

	// pireode overleap

	bool overLapDate(FullDa FDate1, FullDa FDate2) {
		if (FDate1.DateEnd.month > FDate2.DateStart.month) {
			return true;
		}
		else if (FDate1.DateEnd.day > FDate2.DateStart.day) {
			return true;
		}

		return false;

	}

	// priode of length 

	short priodeLength(FullDa d1, bool includingEndDay = false) {
		return diffrenceDay(d1.DateStart, d1.DateEnd, includingEndDay);
	}

	////========================///
	bool checkIsDayToBeBetweenRangDate(FullDa dateF, Sdate dateCheck) {
		return (dateCheck.day >= dateF.DateStart.day) && (dateCheck.day <= dateF.DateEnd.day);
	}

	short countOverLap(FullDa d1, FullDa d2) {
		short count = 0;
		while (checkIsDayToBeBetweenRangDate(d1, d2.DateStart))
		{
			count++;

			d2.DateStart = IncreaseDateByOneDay(d2.DateStart);
		}

		return --count;
	}

	// vecation day
	bool checkValationDay(Sdate d1) {

		if (d1.day == dayOfMonth(d1.year, d1.month)) {
			return true;
		}

		return false;
	}

	// convert date 
	string DateString() {
		string value;
		cout << "Pleaes enter Date dd/mm/yyyy ? ";
		getline(cin, value);

		return value;
	}

	
	string convertDateStructerToString(Sdate d1) {
		string DateWord = "";
		DateWord += to_string(d1.day) + "/";
		DateWord += to_string(d1.month) + "/";
		DateWord += to_string(d1.year);

		return DateWord;
	}




}