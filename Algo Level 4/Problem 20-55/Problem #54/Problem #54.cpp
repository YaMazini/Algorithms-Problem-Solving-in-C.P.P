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

stDate IncreaseDateByOneDay(stDate Date)
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

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
		/ 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Days, Date.Month, Date.Year);
}

string DayOfWeekShortName(short DayOrder)
{
	string Arr[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return Arr[DayOrder];
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Days < Date2.Days : false)) : false);
}

bool IsItEndOfWeek(short DayOrder)
{
	return (DayOrder == 6);
}

bool IsItWeekEnd(short DayOrder)
{
	return (DayOrder == 5 || DayOrder == 6);
}

short CalculateVacationDays(stDate Date1, stDate Date2)
{
	short DaysCounter = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Date1 = IncreaseDateByOneDay(Date1);

		if (!IsItWeekEnd(DayOfWeekOrder(Date1)))
		{
			DaysCounter++;
		}
	}

	return DaysCounter;
}



int main()
{
	cout << " Vacation Starts: \n";
	stDate DateFrom = ReadDate();

	cout << "\n Vacation Ends: \n";
	stDate DateTo = ReadDate();

	cout << "\n Vacation From: " << DayOfWeekShortName(DayOfWeekOrder(DateFrom)) << " , "
	   	 << DateFrom.Days << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;

	cout << " Vacation To  : " << DayOfWeekShortName(DayOfWeekOrder(DateTo)) << " , "
		 << DateTo.Days << "/" << DateTo.Month << "/" << DateTo.Year << "\n\n";
	

	cout << " Actual Vacation Days is: " << CalculateVacationDays(DateFrom, DateTo) << endl;
	 


	return 0;
}