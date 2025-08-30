#include <iostream>
#include <cmath>
using namespace std;


float ReadNumber(string Message)
{
	float Number = 0;
	cout << Message;
	cin >> Number;

	return Number;
}

float MyABS(float Number)
{
	if (Number <= 0)
		return Number * -1;

	return Number;
}


int main()
{
	float Number = ReadNumber("Please enter a number: ");

	cout << "\n My abs Result: " << MyABS(Number);
	cout << "\n C++ abs Result: " << abs(Number) << "\n";

	
	return 0;
}