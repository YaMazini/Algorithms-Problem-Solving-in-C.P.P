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

bool IsEquivilant(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year && Date1.Month == Date2.Month
		&& Date1.Days == Date2.Days);
}


int main()
{
	stDate Date1;
	stDate Date2;

	cout << " Date 1: \n";
	Date1 = ReadDate();

	cout << "\n Date 2: \n";
	Date2 = ReadDate();


	if (IsEquivilant(Date1, Date2))
	{
		cout << "\n Both Dates are the same. \n ";
	}

	else
	{
		cout << "\n Both Days are NOT the same \n ";
	}


	return 0;
}