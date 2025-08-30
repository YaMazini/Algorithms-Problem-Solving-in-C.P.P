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

int main()
{

	stDate Date;

	cout << " Date 1: \n";
	Date = ReadDate();


	if (IsLastMonth(Date.Month))
		cout << "\n The Month is the last Month in Year. \n";
	
	else
		cout << "\n The Month is NOT the last Month in Year. \n";
	

	if (IsLastDay(Date))
		cout << "\n The Day is the last Day in Month. \n";

	else
		cout << "\n The Day is NOT the last Day in Month. \n";


	return 0;
}