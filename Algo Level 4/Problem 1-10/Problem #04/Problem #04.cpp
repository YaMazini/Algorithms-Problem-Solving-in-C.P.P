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


bool IsLeapYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0) && (Year % 100 != 0);
}

short NumberOfDaysInYear(short Year)
{
	return (IsLeapYear(Year)) ? 366 : 365;
}

short NumberOfHoursInYear(short Year)
{
	return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year)
{
	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year)
{
	return NumberOfMinutesInYear(Year) * 60;
}


int main()
{
	short Year = ReadNumber("Please enter the year: ");

	cout << "\n Number of Days      in Year [" << Year << "] is: "
		<< NumberOfDaysInYear(Year);

	cout << "\n Number of Hours     in Year [" << Year << "] is: "
		<< NumberOfHoursInYear(Year);

	cout << "\n Number of Minutes   in Year [" << Year << "] is: "
		<< NumberOfMinutesInYear(Year);

	cout << "\n Number of Seconds   in Year [" << Year << "] is: "
		<< NumberOfSecondsInYear(Year) << endl;

	return 0;
}