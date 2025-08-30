#include <iostream>
#include <vector>
#include <string>
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


short DayOrderInWeek(short Year, short Month, short Day)
{
	short a = 0, y = 0, m = 0;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortname(short DayOrder)
{
	string DaysInWeek[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	return DaysInWeek[DayOrder];
}


int main()
{
	short Year = ReadNumber("Please enter Year to check: ");
	short Month = ReadNumber("Please enter Month to check: ");
	short Day = ReadNumber("Please enter Day to check: ");

	short DayOrder = DayOrderInWeek(Year, Month, Day);


	cout << "Date       : " << Day << "/" << Month << "/" << Year << endl;
	cout << "Days Order : " << DayOrder << endl;
	cout << "Day Name   : " << DayShortname(DayOrder) << endl;


	
	return 0;
}