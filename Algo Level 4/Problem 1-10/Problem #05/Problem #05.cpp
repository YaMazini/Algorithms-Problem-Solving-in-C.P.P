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
		return 0;


	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	
	short Arr30DayMonths[4] = {4, 6, 9, 11};
	for (short i = 0; i < 4; i++)
	{
		if (Month == Arr30DayMonths[i])
		{
			return 30;
		}
	}


	return 31;
}

short NumberOfHoursInMonth(short Year, short Month)
{
	return NumberOfDaysInMonth(Year, Month) * 24;
}

int NumberOfMinutesInMonth(short Year, short Month)
{
	return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSecondsInMonth(short Year, short Month)
{
	return NumberOfMinutesInMonth(Year, Month) * 60;
}


int main()
{
	short Year = ReadNumber("Please enter the year: ");
	short Month = ReadNumber("Please enter the month: ");


	cout << "\n Number of Days      in Mounth [" << Month << "] is: "
		<< NumberOfDaysInMonth(Year, Month);

	cout << "\n Number of Hours     in Mounth [" << Month << "] is: "
		<< NumberOfHoursInMonth(Year, Month);

	cout << "\n Number of Minutes   in Mounth [" << Month << "] is: "
		<< NumberOfMinutesInMonth(Year, Month);

	cout << "\n Number of Seconds   in Mounth [" << Month << "] is: "
		<< NumberOfSecondsInMonth(Year, Month) << endl;



	return 0;
}