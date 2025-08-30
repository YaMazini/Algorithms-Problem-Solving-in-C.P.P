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

stDate IncreaseDateByXDays(stDate Date, short Days)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}


stDate IncreaseDateByOneWeek(stDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date); //or Call IncreaseDateByXDays(Date, 7)
	}

	return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, short Weeks)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;
}


stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}

	else 
	{
		++Date.Month;
	}

	short DaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
	
	if (Date.Days > DaysInCurrentMonth)
	{
		Date.Days = DaysInCurrentMonth;
	}

	return Date;
}

stDate IncreaseDateByXMonths(stDate Date, short Months)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}


stDate IncreaseDateByOneYear(stDate Date)
{
	++Date.Year;
	return Date;
}

stDate IncreaseDateByXYears(stDate Date, short Years)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short Years)
{
	Date.Year += Years;
	return Date;
}


stDate IncreaseDateByOneDecade(stDate Date)
{
	Date.Year += 10;
	return Date;
}

stDate IncreaseDateByXDecades(stDate Date, short Decades)
{
	for (short i = 1; i <= Decades; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}

	return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, short Decades)
{
	Date.Year += (Decades * 10);
	return Date;
}


stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	Date.Year += 1000;
	return Date;
}


int main()
{
	short X = 10;

	cout << " Date : \n";
	stDate Date = ReadDate();


	cout << "\n Date After: \n\n";

	Date = IncreaseDateByOneDay(Date);
	cout << "01-Adding one day is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXDays(Date, X);
	cout << "02-Adding " << X << " days is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	Date = IncreaseDateByOneWeek(Date);
	cout << "03-Adding one Week is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXWeeks(Date, X);
	cout << "04-Adding " << X << " Week is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;
	

	Date = IncreaseDateByOneMonth(Date);
	cout << "05-Adding one Month is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXMonths(Date, 5);
	cout << "06-Adding " << 5 << " Months is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	Date = IncreaseDateByOneYear(Date);
	cout << "07-Adding one Year is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXYears(Date, X);
	cout << "08-Adding " << X << " Years is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXYearsFaster(Date, X);
	cout << "09-Adding " << X << " Years (Faster) is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	Date = IncreaseDateByOneDecade(Date);
	cout << "10-Adding one Decade is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXDecades(Date, X);
	cout << "11-Adding " << X << " Decades is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXDecadesFaster(Date, X);
	cout << "12-Adding " << X << " Decades (Faster) is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	Date = IncreaseDateByOneCentury(Date);
	cout << "13-Adding one Century is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	Date = IncreaseDateByOneMillennium(Date);
	cout << "14-Adding one Millennium is: " << Date.Days << "/" << Date.Month << "/" << Date.Year << endl;


	return 0;
}