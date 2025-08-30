#include <iostream>
#include <vector>
#include <string>
using namespace std;

short ReadNumber(string Message)
{
	short Number = 0;
	cout << Message;
	cin >> Number;
	cout << "\n";

	return Number;
}

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0) && (Year % 100 != 0);
}


int main()
{
	short Year = ReadNumber("Please enter a Number: ");



	return 0;
}