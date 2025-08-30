#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Days = 0;
};

short ReadNumber(string Message)
{
	short Number = 0;
	cout << Message;
	cin >> Number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please enter a number: ";
		cin >> Number;
	}

	cout << "\n";

	return Number;
}


bool IsLeapYear(short Year)
{
	return (Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0));
}

short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	short ArrDays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : ArrDays[Month];
}

short DaysFromBeginningOfYear(short Year, short Month, short Day)
{
	short DaysCounter = 0;
	for (short i = 1; i <= Month - 1; i++)
	{
		DaysCounter += NumberOfDaysInMonth(Year, i);
	}

	DaysCounter += Day;
	return DaysCounter;
}


stDate DateByDaysFromBeginningOfYear(short Year, short Days)
{
	stDate Date;
	Date.Year = Year;
	Date.Month = 1;
	Date.Days = 0;

	short MonthDays = 0;
	short RemainingDays = Days;

	while (true)
	{
		MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}

		else
		{
			Date.Days = RemainingDays;
			return Date;
		}
	}

	return Date;
}


int main()
{
	short Year = ReadNumber("Please enter Year: ");
	short Month = ReadNumber("Please enter Month: ");
	short Day = ReadNumber("Please enter Day: ");

	short Days = DaysFromBeginningOfYear(Year, Month, Day);
	stDate Date = DateByDaysFromBeginningOfYear(Year, Days);

	cout << "Number of Days from the begining of the year is: "
		<< Days << endl;

	cout << "Date for [" << Days << "] is: " << Date.Days << "/" << Date.Month  << "/" << Date.Year << endl;


	return 0;
}