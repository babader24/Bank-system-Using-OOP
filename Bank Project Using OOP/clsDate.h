#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#pragma warning(disable : 4996)

using namespace std;
class clsDate
{
private:
	short _Day;
	short _Month;
	short _Year;
public:
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
	}
	clsDate(string date)
	{
		clsDate Date = stringToDate(date);
		dateToString(Date);

	}
	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(short DayOfMonth, short Year)
	{
		convertDaysToDate(DayOfMonth, Year);
		_Year = Year;
	}
	void print()
	{
		cout << _Day << "/" << _Month << "/" << _Year;
	}
	vector<string> splitString(string name, string deline)
	{
		vector <string> vSpilt;
		string word;
		short po, counter = 0;

		while ((po = name.find(deline)) != string::npos)
		{
			word = name.substr(0, po);
			if (word != "")
			{
				vSpilt.push_back(word);
			}
			name.erase(0, po + deline.length());
		}
		if (name != "")
			vSpilt.push_back(name);

		return vSpilt;
	}
	clsDate stringToDate(string name)
	{
		clsDate Date1;
		vector<string>vDate = splitString(name, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

		return Date1;
	}
	static string dateToString(clsDate Date1, string saparator = "/")
	{
		string name = "";
		name += to_string(Date1._Day) + saparator;
		name += to_string(Date1._Month) + saparator;
		name += to_string(Date1._Year);
		return name;
	}
	void dateToString()
	{
		cout << dateToString(*this);
	}
	static bool isLeapYear(int year)
	{
		return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0) ? true : false;
	}
	void isLeapYear()
	{
		cout << isLeapYear(_Year);
	}
	static int MonthDays(int month, int year)
	{
		if (month < 0 || month>12)
			return 0;

		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];
	}
	void MonthDays()
	{
		cout << MonthDays(_Month, _Year);
	}
	void convertDaysToDate(short totalDay, short year)
	{
		int currnMonth = 0;
		short i = 1;
		while (totalDay > MonthDays(i, year))
		{
			totalDay -= MonthDays(i, year);
			currnMonth++;
			i++;
		}
		_Day = totalDay;
		_Month = currnMonth + 1;
		_Year = year;
	}
	static int calcYearDayes(int year)
	{
		return (isLeapYear(year)) ? 366 : 365;
	}
	int calcYearDayes()
	{
		return calcYearDayes(_Year);
	}
	static int calcYearHours(int year)
	{
		return (isLeapYear(year)) ? 366 * 24 : 365 * 24;
	}
	int calcYearHours()
	{
		return calcYearHours(_Year);
	}
	static int calcMinutes(int year)
	{
		return (isLeapYear(year)) ? 366 * 24 * 60 : 365 * 24 * 60;
	}
	int calcMinutes()
	{
		return calcMinutes(_Year);
	}
	static int calcSeconds(int year)
	{
		return (isLeapYear(year)) ? 366 * 24 * 60 * 60 : 365 * 24 * 60 * 60;
	}
	int calcSeconds()
	{
		return calcSeconds(_Year);
	}
	static int daysInMonth(int month, int year)
	{
		if (isLeapYear(year) == true && month == 2)
		{
			return 29;
		}

		switch (month)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 2:
			return 28;
		}
	}
	int daysInMonth()
	{
		return daysInMonth(_Month, _Year);
	}
	static int MonthHours(int month, int year)
	{
		return MonthDays(month, year) * 24;
	}
	int MonthHours()
	{
		return MonthHours(_Month, _Year);
	}
	static int MonthMinutes(int month, int year)
	{
		return MonthHours(month, year) * 60;
	}
	int MonthMinutes()
	{
		return MonthMinutes(_Month, _Year);
	}
	static int MonthSeconds(int month, int year)
	{
		return MonthMinutes(month, year) * 60;
	}
	int MonthSeconds()
	{
		return MonthSeconds(_Month, _Year);
	}
	static short dayOfWeekOrder(short day, short month, short year)
	{
		short a, y, m;

		a = (14 - month) / 12;
		y = year - a;
		m = month + (12 * a) - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short dayOfWeekOrder()
	{
		return dayOfWeekOrder(_Day, _Month, _Year);
	}
	static string daysShortNames(short dayOfTheWeek)
	{
		string arrDaysNames[] =
		{
			"Son","Mon","Teu","Wed","Thu","Fri","Sat"
		};
		return arrDaysNames[dayOfTheWeek];
	}
	string daysShortNames()
	{
		return daysShortNames(dayOfWeekOrder());
	}
	static void printCalender(short year, short month)
	{
		string arrMonths[] =
		{
			"Jan","Feb","Mar","Apr","May","Jun",
			"Jul","Aug","Sep","Oct","Nov","Dec"
		};

		int daysNumbers = MonthDays(month, year);
		short dayOfWeek = dayOfWeekOrder(1, month, year);

		cout << "________________" << arrMonths[month - 1] << "___________________\n";
		cout << "   Sun  Mon  Teu  Wed  Thu  Fri  Sat" << endl;

		short i;
		for (i = 0; i < dayOfWeek; i++)
			printf("     ");

		for (short j = 1; j <= daysNumbers; j++)
		{
			{
				printf("%5d", j);
				i++;
			}
			if (i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		cout << "\n________________________________________\n";
	}
	void printCalender()
	{
		return printCalender(_Year, _Month);
	}
	static void printYearCalender(short year)
	{
		cout << "___________________________________\n";
		cout << "       Full Calender Of " << year << "\n";
		cout << "___________________________________\n";

		for (short month = 1; month <= 12; month++)
		{
			printCalender(year, month);
		}
	}
	void printYearCalender()
	{
		return printYearCalender(_Year);
	}
	static int totalDaysFromBeginning(short day, short month, short year)
	{
		int totalDays = 0;

		for (short i = 1; i < month; i++)
		{
			totalDays += MonthDays(i, year);
		}
		return totalDays + day;
	}
	int totalDaysFromBeginning()
	{
		return totalDaysFromBeginning(_Day, _Month, _Year);
	}
	static void addDaysToDate(short day, short month, short year, int addDays)
	{
		addDays += day;
		while (addDays > 365 || addDays > 366)
		{
			year++;
			if (isLeapYear(year))
				addDays -= 366;
			else
				addDays -= 365;

		}
		for (short i = 1; addDays > MonthDays(i, year); i++)
		{
			addDays -= MonthDays(i, year);
			month++;
			if (month == 13)
			{
				year++;
				month = 1;
			}
		}
		cout << addDays << "/" << month << "/" << year;
	}
	void addDaysToDate(int moreDays)
	{
		return addDaysToDate(_Day, _Month, _Year, moreDays);
	}
	static bool isDate1BeforeDate2(clsDate date1, clsDate date2)
	{
		if (date1._Year < date2._Year)
			return true;
		else if (date1._Month < date2._Month)
			return true;
		else if (date1._Day < date2._Day)
			return true;

		return false;
	}
	bool isDate1BeforeDate2(clsDate date2)
	{
		return isDate1BeforeDate2(*this, date2);
	}
	static bool isDate1EqualToDate2(clsDate date1, clsDate date2)
	{
		return date1._Year == date2._Year ? date1._Month == date2._Month ? date1._Day == date2._Day ?
			true : false : false : false;
	}
	bool isDate1EqualToDate2(clsDate date2)
	{
		return isDate1EqualToDate2(*this, date2);
	}
	static bool isLastDay(short day, short month, short year)
	{
		return day == MonthDays(month, year) ? true : false;
	}
	bool isLastDay()
	{
		return isLastDay(_Day, _Month, _Year);
	}
	static bool isLastMonth(short month)
	{
		return 12 == month ? true : false;
	}
	bool isLastMonth()
	{
		return isLastMonth(_Month);
	}
	static clsDate increaseOneDay(clsDate& date)
	{
		if (isLastDay(date._Day, date._Month, date._Year))
		{
			if (isLastMonth(date._Month))
			{
				date._Day = 1;
				date._Month = 1;
				date._Year++;
			}
			else
			{
				date._Day = 1;
				date._Month++;
			}
		}
		else
		{
			date._Day += 1;
		}
		//cout << "Date After Increase One Day = " <<
		//	date._Day << "/" << date._Month << "/" << date._Year << endl;
		return date;
	}
	void increaseOneDay()
	{
		increaseOneDay(*this);
		return printTheDate(*this);
	}
	static void printTheDate(clsDate date)
	{
		cout << "Date After Increase One Day = " <<
			date._Day << "/" << date._Month << "/" << date._Year << endl;
	}
	void printTheDate()
	{
		return printTheDate(*this);
	}
	static void differenceBetweenSmallDateAndBigDate(clsDate date1, clsDate date2, bool endDay = true)
	{
		int difDays = 0;
		while (date1._Year != date2._Year)
		{
			date1._Year++;
			difDays += isLeapYear(date1._Year) ? 366 : 365;
		}
		while (date1._Month != date2._Month)
		{
			date1._Month++;
			difDays += MonthDays(date1._Month, date1._Year);
		}
		while (date1._Day != date2._Day)
		{
			date1._Day++;
			difDays++;
		}
		cout << "\nDiffrenece is: [" << difDays << "] Days.\n";
		if (endDay)
		{
			cout << "\nDiffrenece (Include End Day) is: [" << difDays + 1 << "] Days.\n";
		}
	}
	void differenceBetweenSmallDateAndBigDate(clsDate date2)
	{
		return differenceBetweenSmallDateAndBigDate(*this, date2);
	}
	static clsDate getSysDate()
	{
		clsDate date;

		time_t t = time(0);
		tm* now = localtime(&t);

		date._Year = now->tm_year + 1900;
		date._Month = now->tm_mon + 1;
		date._Day = now->tm_mday;

		return date;
	}
	static void printSysDate()
	{
		clsDate date;

		time_t t = time(0);
		tm* now = localtime(&t);

		date._Year = now->tm_year + 1900;
		date._Month = now->tm_mon + 1;
		date._Day = now->tm_mday;

		cout << date._Day << "/" << date._Month << "/" << date._Year;
	}
	void YourAgeInDays()
	{
		return differenceBetweenSmallDateAndBigDate(getSysDate());
	}
	static bool isEndOfWeek(short dayOrder)
	{
		return daysShortNames(dayOrder) == "Sat";
	}
	bool isEndOfWeek()
	{
		return isEndOfWeek(dayOfWeekOrder());
	}
	static bool isWeekEnd(short dayOrder)
	{
		return daysShortNames(dayOrder) == "Sat" || "Fri";
	}
	bool isWeekEnd()
	{
		return isWeekEnd(dayOfWeekOrder());
	}
	static bool isBusinessDay(short dayOrder)
	{
		return daysShortNames(dayOrder) == "Son" || "Mon" || "Teu" || "Wed" || "Thu";
	}
	bool isBusinessDay()
	{
		return isBusinessDay(dayOfWeekOrder());
	}
	static bool isBusinessDayFromDate(clsDate date)
	{
		short dayIndex = dayOfWeekOrder(date._Day, date._Month, date._Year);
		return (dayIndex >= 0 && dayIndex <= 4);
	}
	bool isBusinessDayFromDate()
	{
		return isBusinessDayFromDate(*this);
	}
	static int daysUntilWeekEnd(short dayOrder)
	{
		short num = 0;
		for (short i = dayOrder + 1; i < 7; i++)
			num++;
		return num;
	}
	int daysUntilWeekEnd()
	{
		return daysUntilWeekEnd(dayOfWeekOrder());
	}
	static int daysUntilMonthEnd(short days, short month, short year)
	{
		return  MonthDays(month, year) - days;
	}
	int daysUntilMonthEnd()
	{
		return daysUntilMonthEnd(_Day, _Month, _Year);
	}
	static int daysUntilYearEnd(short day, short month, short year)
	{
		int remindDays = 0;
		for (short i = 1; i < month; i++)
		{
			remindDays += MonthDays(i, year);
		}
		remindDays += day;
		return isLeapYear(year) ? 366 - remindDays : 365 - remindDays;
	}
	int daysUntilYearEnd()
	{
		return daysUntilYearEnd(_Day, _Month, _Year);
	}
	static short calcVacationDays(clsDate date1, clsDate date2)
	{
		short dayCounter = 0;

		while (isDate1BeforeDate2(date1, date2))
		{
			if (isBusinessDayFromDate(date1))
				dayCounter++;

			increaseOneDay(date1);
		}
		return dayCounter;
	}
	short calcVacationDays(clsDate date)
	{
		return calcVacationDays(*this, date);
	}
	static clsDate calcVacationReturnDate(clsDate& date1, short vecationDays)
	{
		short dayCounter = 0;

		while (vecationDays > 0)
		{
			if (isBusinessDayFromDate(date1))
				vecationDays--;

			increaseOneDay(date1);
		}
		return date1;
	}
	void calcVacationReturnDate(short vecationDays)
	{
		calcVacationReturnDate(*this, vecationDays);
		return printTheDate(*this);
	}
	static bool isDate1AfterDate2(clsDate date1, clsDate date2)
	{
		return (!isDate1BeforeDate2(date1, date2) && !isDate1EqualToDate2(date1, date2));
	}
	bool isDate1AfterDate2(clsDate date)
	{
		return isDate1AfterDate2(*this, date);
	}
	static bool isValidateDate(clsDate date)
	{
		return  (date._Day > 0 && date._Day <= MonthDays(date._Month, date._Year))
			&&
			(date._Month > 0 && date._Month < 13);
	}
	bool isValidateDate()
	{
		return isValidateDate(*this);
	}
};

