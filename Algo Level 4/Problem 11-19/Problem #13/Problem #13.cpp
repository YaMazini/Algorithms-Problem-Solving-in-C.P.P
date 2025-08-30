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

bool AreEqivalant(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year && Date1.Month == Date2.Month
		    && Date1.Days == Date2.Days);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	if (Date1.Year > Date2.Year)
	{
		return true;
	}

	if (Date1.Year < Date2.Year)
	{
		return false;
	}

	short Date1Days = DaysFromBeginningOfYear(Date1.Year, Date1.Month, Date1.Days);
	short Date2Days = DaysFromBeginningOfYear(Date2.Year, Date2.Month, Date2.Days);

	return (Date1Days > Date2Days);
}



int main()
{

	stDate Date1;
	stDate Date2;

	cout << " Date 1: \n";
	Date1 = ReadDate();

	cout << "\n Date 2: \n";
	Date2 = ReadDate();


	if (AreEqivalant(Date1, Date2))
	{
		cout << "\n Both Dates are the same. \n ";
	}

	else if (IsDate1BeforeDate2(Date1, Date2))
	{
		cout << "\n First Date is NOT LESS than the Second Date! \n ";
	}

	else
	{
		cout << "\n First Date is LESS than the Second Date! \n ";
	}


	return 0;
}