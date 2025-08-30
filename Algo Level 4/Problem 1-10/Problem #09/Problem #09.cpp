#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

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

short DaysNumberInMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	short ArrDays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : ArrDays[Month];
}

string MonthShortName(short Month)
{
	string ArrMonth[] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return ArrMonth[Month];
}

short DayOrderInWeek(short Year, short Month, short Day)
{
	short a = 0, y = 0, m = 0;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOrder)
{
	string DaysInWeek[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return DaysInWeek[DayOrder];
}


void PrintCalenderHeader(string MonthName)
{
	cout << "  _______________" << MonthName << "_______________\n\n";

	cout << right << setw(5) << "Sun";
	cout << right << setw(5) << "Mon";
	cout << right << setw(5) << "Tue";
	cout << right << setw(5) << "Wed";
	cout << right << setw(5) << "Thu";
	cout << right << setw(5) << "Fri";
	cout << right << setw(5) << "Sat";

	cout << endl;
}

void PrintMonthCalender(short Year, short Month)
{
	string MonthName = MonthShortName(Month);
	short FirstDayOrder = DayOrderInWeek(Year, Month, 1);

	PrintCalenderHeader(MonthName);

	for (short i = 0; i < FirstDayOrder; i++)
	{
		cout << right << setw(5) << "";
	}

	short Counter = FirstDayOrder;
	for (short j = 1; j <= DaysNumberInMonth(Year, Month); j++)
	{
		cout << right << setw(5) << j;
		if (++Counter == 7)
		{
			Counter = 0;
			cout << "\n";
		}
	}
	cout << "\n  _________________________________\n\n";
}


void PrintYearCalenderHeader(short Year)
{
	cout << "\n  _________________________________\n";
	cout << "\n\t   Calender - " << Year << endl;
	cout << "  _________________________________\n";
}

void PrintYearCalender(short Year)
{
	PrintYearCalenderHeader(Year);

	for (short i = 1; i <= 12; i++)
	{
		PrintMonthCalender(Year, i);
	}
}



int main()
{
	short Year = ReadNumber("Please enter Year to check: ");

	PrintYearCalender(Year);


	return 0;
}