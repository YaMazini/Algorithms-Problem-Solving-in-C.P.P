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

short NumberOfDaysInYear(short Year)
{
	return (IsLeapYear(Year)) ? 366 : 365;
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

	short RemainingDays = Days;


	while (true)
	{
		if (RemainingDays > NumberOfDaysInMonth(Date.Year, Date.Month))
		{
			RemainingDays -= NumberOfDaysInMonth(Date.Year, Date.Month);
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

stDate DateAfterAddingDays(stDate Date, short Days)
{
	short RemainingDays = Days + DaysFromBeginningOfYear(Date.Year, Date.Month, Date.Days);
	short DaysInYear = 0;

	while (true)
	{
		short DaysInYear = NumberOfDaysInYear(Date.Year);

		if (RemainingDays > DaysInYear)
		{
			RemainingDays -= DaysInYear;
			Date.Year++;
		}


		else
		{
			Date = DateByDaysFromBeginningOfYear(Date.Year, RemainingDays);
			return Date;
		}
	}

	return Date;
}

stDate ReadDate()
{
	stDate Date;

	Date.Year = ReadNumber("Please enter a Year: ");
	Date.Month = ReadNumber("Please enter a Month: ");
	Date.Days = ReadNumber("Please enter a Day: ");

	return Date;
}


int main()
{
	stDate Date = ReadDate();

	short DaysToAdd = ReadNumber("How many days to add: ");

	Date = DateAfterAddingDays(Date, DaysToAdd);

	cout << "Date after adding [" << DaysToAdd << "] Days is: "
	   	 << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;
	

	

	return 0;
}