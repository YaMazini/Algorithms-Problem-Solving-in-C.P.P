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
	string Arr[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	return Arr[DayOrder];
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Days < Date2.Days : false)) : false);
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


bool IsItEndOfWeek(short DayOrder)
{
	return (DayOrder == 6);
}

string EndOfWeekCheckingResult(short DayOrder)
{
	return IsItEndOfWeek(DayOrder) ? "\n Yes It is End of week." : "\n No NOT end of week.";
}


bool IsItWeekEnd(short DayOrder)
{
	return (DayOrder == 5 || DayOrder == 6);
}

string WeekEndCheckingResult(short DayOrder)
{
	return (IsItWeekEnd(DayOrder)) ? "\n Yes it is a week end." : "\n No it is NOT week end.";
}


bool IsItBusinessDay(short DayOrder)
{
	return (IsItWeekEnd(DayOrder)) ? false : true;
}

string BusinessDayCheckingResult(short DayOrder)
{
	return (IsItBusinessDay(DayOrder)) ? "\n Yes it is a Business Day." : "\n No it is NOT a Business Day.";
}


short DaysUntilEndOfWeek(stDate Date)
{
	short DayCounter = 0;

	while (!IsItEndOfWeek(DayOfWeekOrder(Date)))
	{
		Date = IncreaseDateByOneDay(Date);
		DayCounter++;
	}

	return DayCounter;
}

short DaysUntilEndOfMonth(stDate Date)
{
	stDate EndOfMonthDate;
	EndOfMonthDate.Year = Date.Year;
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Days = NumberOfDaysInMonth(EndOfMonthDate.Year, EndOfMonthDate.Month);

	return GetDifferenceInDays(Date, EndOfMonthDate);
}

short DaysUntilEndOfYear(stDate Date)
{
	stDate EndOfYearDate;

	EndOfYearDate.Year = Date.Year;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Days = 31;

	return GetDifferenceInDays(Date, EndOfYearDate);
}

stDate GetSystemDate()
{
	stDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Days = now->tm_mday;
	return Date;
}



int main()
{
	cout << " Date : \n";
	stDate Date = GetSystemDate();

	short DayOrder = DayOfWeekOrder(Date);

	cout << "\nToday is " << DayOfWeekShortName(DayOrder) << " , "
		 << Date.Days << "/" << Date.Month << "/" << Date.Year << "\n\n";

	cout << "Is it End of Week ?";
	cout << EndOfWeekCheckingResult(DayOrder) << "\n\n";

	cout << "It is Weekend ?";
	cout << WeekEndCheckingResult(DayOrder) << "\n\n";
	
	cout << "Is it Business Day ?";
	cout << BusinessDayCheckingResult(DayOrder) << "\n\n";
	
	cout << "Days until end of week: " << DaysUntilEndOfWeek(Date) << " Day(s)." << endl;
	cout << "Days until end of Month: " << DaysUntilEndOfMonth(Date) << " Day(s)." << endl;
	cout << "Days until end of Year: " << DaysUntilEndOfYear(Date) << " Day(s)." << endl;


	return 0;
}