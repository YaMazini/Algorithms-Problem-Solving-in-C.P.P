#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
using namespace std;

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Days = 0;
};

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
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

stPeriod ReadPeriod()
{
	stPeriod Period;

	cout << "Enter Start Date: \n\n";
	Period.StartDate = ReadDate();

	cout << "\nEnter End Date: \n\n";
	Period.EndDate = ReadDate();

	return Period;
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Days < Date2.Days : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Days == Date2.Days) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return !(IsDate1BeforeDate2(Date1, Date2) && IsDate1EqualDate2);
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false)
{
	return GetDifferenceInDays(Period.StartDate, Period.EndDate,
		IncludeEndDate);
}

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
	if (CompareDates(Period1.EndDate, Period2.StartDate) == enDateCompare::Before
		||
		CompareDates(Period1.StartDate, Period2.EndDate) == enDateCompare::After)
	{
		return false;
	}

	return true;
}

bool IsDateInPeriod(stPeriod Period, stDate Date)
{
	if (CompareDates(Date, Period.StartDate) == enDateCompare::After
		&&
		CompareDates(Date, Period.EndDate) == enDateCompare::Before)
	{
		return true;
	}

	return false;
}

int OverlapDaysCount(stPeriod Period1, stPeriod Period2)
{
	int DaysCounter = 0;
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);

	if (!IsOverlapPeriods(Period1, Period2))
		return 0;

	if (Period1Length < Period2Length)
	{
		while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
		{
			if (IsDateInPeriod(Period2, Period1.StartDate))
			{
				DaysCounter++;
			}

			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	
	}

	else
	{
		while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
		{
			if (IsDateInPeriod(Period1, Period2.StartDate))
			{
					DaysCounter++;
			}

			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}
	
	return DaysCounter;
}



int main()
{
	cout << " Period1: \n";
	stPeriod Period1 = ReadPeriod();

	cout << "\n Period2: \n\n";
	stPeriod Period2 = ReadPeriod();

	cout << "\n Overlap Days count: " << OverlapDaysCount(Period1, Period2) << endl;

	return 0;
}