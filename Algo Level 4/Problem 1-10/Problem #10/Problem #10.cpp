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

short NumberOfDaysInMonth(short Year, short Month)
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



int main()
{
	short Year = ReadNumber("Please enter Year: ");
	short Month = ReadNumber("Please enter Month: ");
	short Day = ReadNumber("Please enter Day: ");
	
	cout << "Number of Days from the begining of the year is: "
		 << DaysFromBeginningOfYear(Year, Month, Day) << endl;

	return 0;
}