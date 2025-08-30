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


short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	short ArrNumOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : ArrNumOfDays[Month - 1];
}



int main()
{
	short Year = ReadNumber("Please enter the year: ");
	short Month = ReadNumber("Please enter the month: ");


	cout << "\n Number of Days in Mounth [" << Month << "] is: "
		 << NumberOfDaysInMonth(Year, Month) << endl;



	return 0;
}