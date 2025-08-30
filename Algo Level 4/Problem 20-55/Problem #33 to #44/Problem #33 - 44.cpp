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


bool IsFirstMonth(short Month)
{
	return (Month == 1);
}

bool IsFirstDay(short Day)
{
	return (Day == 1);
}


stDate DecreaseDateByOneDay(stDate Date)
{
	if (IsFirstDay(Date.Days))
	{
		if (IsFirstMonth(Date.Month))
		{
			Date.Year--;
			Date.Month = 12;
			Date.Days = 31;
		}

		else
		{
			--Date.Month;
			Date.Days = NumberOfDaysInMonth(Date.Year, Date.Month);
		}

		return Date;
	}

	--Date.Days;


	return Date;
}

stDate DecreaseDateByXDays(stDate Date, short Days)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}


stDate DecreaseDateByOneWeek(stDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date); //or Call DecreaseDateByXDays(Date, 7)
	}

	return Date;
}

stDate DecreaseDateByXWeeks(stDate Date, short Weeks)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}

	return Date;
}


stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Year--;
		Date.Month = 12;
	}

	else
	{
		Date.Month--;
	}

	short CurrentMonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);

	if (Date.Days == 1)
	{
		Date.Days = CurrentMonthDays;
	}

	return Date;
}

stDate DecreaseDateByXMonths(stDate Date, short Months)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}


stDate DecreaseDateByOneYear(stDate Date)
{
	--Date.Year;
	return Date;
}

stDate DecreaseDateByXYears(stDate Date, short Years)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, short Years)
{
	Date.Year -= Years;
	return Date;
}


stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year -= 10;
	return Date;
}

stDate DecreaseDateByXDecades(stDate Date, short Decades)
{
	for (short i = 1; i <= Decades; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}

	return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date, short Decades)
{
	Date.Year -= (Decades * 10);
	return Date;
}


stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;
	return Date;
}


int main()
{
	short X = 10;

	cout << " Date : \n";
	stDate Date = ReadDate();


	cout << "\n Date After: \n\n";

	Date = DecreaseDateByOneDay(Date);
	cout << "01-Subtracting one day is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXDays(Date, X);
	cout << "02-Subtracting " << X << " days is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	Date = DecreaseDateByOneWeek(Date);
	cout << "03-Subtracting one Week is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXWeeks(Date, X);
	cout << "04-Subtracting " << X << " Week is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	Date = DecreaseDateByOneMonth(Date);
	cout << "05-Subtracting one Month is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXMonths(Date, 5);
	cout << "06-Subtracting " << 5 << " Months is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	Date = DecreaseDateByOneYear(Date);
	cout << "07-Subtracting one Year is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXYears(Date, X);
	cout << "08-Subtracting " << X << " Years is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXYearsFaster(Date, X);
	cout << "09-Subtracting " << X << " Years (Faster) is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	Date = DecreaseDateByOneDecade(Date);
	cout << "10-Subtracting one Decade is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXDecades(Date, X);
	cout << "11-Subtracting " << X << " Decades is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXDecadesFaster(Date, X);
	cout << "12-Subtracting " << X << " Decades (Faster) is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	Date = DecreaseDateByOneCentury(Date);
	cout << "13-Subtracting one Century is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	Date = DecreaseDateByOneMillennium(Date);
	cout << "14-Subtracting one Millennium is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	return 0;
}