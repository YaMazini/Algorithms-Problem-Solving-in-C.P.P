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
	if (Year % 400 == 0)
		return true;

	if ((Year % 4 == 0) && !(Year % 100 == 0))
		return true;


	return false;
}


int main()
{
	short Year = ReadNumber("Please enter a Number: ");


	if (IsLeapYear(Year))
		cout << "\n " << Year << " is a Leap Year! \n";
	

	else 
		cout << "\n " << Year << " is NOT a Leap Year! \n";


	return 0;
}