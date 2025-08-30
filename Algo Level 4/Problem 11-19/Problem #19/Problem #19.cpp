#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
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

	return Number;
}

stDate ReadDate()
{
	stDate Date;

	Date.Year = ReadNumber("Please enter a Year: ");
	Date.Month = ReadNumber("Please enter a Month: ");
	Date.Days = ReadNumber("Please enter a Day: ");

	return Date;
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


bool IsLastMonth(short Month)
{
	return (Month == 12);
}

bool IsLastDay(stDate Date)
{
	return (Date.Days == NumberOfDaysInMonth(Date.Year, Date.Month));
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Days < Date2.Days : false)) : false);
}

stDate IncreaseDayByOneDay(stDate Date)
{
	if (IsLastDay(Date))
	{
		if (IsLastMonth(Date.Month))
		{
			Date.Days = 1;
			Date.Month = 1;
			Date.Year++;
		}

		else
		{
			Date.Days = 1;
			Date.Month++;
		}
	}

	else
	{
		Date.Days++;
	}

	return Date;
}

void SwapDates(stDate& Date1, stDate& Date2)
{
	stDate TempDate = Date1;
	Date1 = Date2;
	Date2 = TempDate;
}


int DifferenceBetweenDates(stDate Date1, stDate Date2, bool IncludeLastDay = false)
{
	int DaysCounter = 0;
	short SwapFlagValue = 1;

	if (!IsDate1BeforeDate2(Date1, Date2))
	{
		SwapDates(Date1, Date2);
		SwapFlagValue = -1;
	}

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Date1 = IncreaseDayByOneDay(Date1);
		DaysCounter++;
	}

	return (IncludeLastDay) ? (++DaysCounter) * SwapFlagValue : DaysCounter * SwapFlagValue;
}



int main()
{
	cout << " Date 1: \n";
	stDate Date1 = ReadDate();

	cout << "\n Date 2: \n";
	stDate Date2 = ReadDate();

	cout << "\n Difference is: " << DifferenceBetweenDates(Date1, Date2) << " Days(s). \n";
	cout << "\n Difference (Includeing End Day) is: "
		 << DifferenceBetweenDates(Date1, Date2, true) << " Day(s). \n";

	return 0;
}