#include <iostream>
#include <string>
using namespace std;


float ReadNumber(string Message)
{
	float Number;
	cout << Message, cin >> Number;

	return Number;
}

float SumNumbers_UntilEntering_minus99()
{
	float sum = 0;
	int Counter = 1;
	float Number = ReadNumber("Please enter Number " + to_string(Counter) + ": ");


	while (Number != -99)
	{
		Counter++ ;
		sum += Number;

		Number = ReadNumber("Please Enter a Number " + to_string(Counter) + ": ");
	}

	return sum;
}



int main()
{
	cout << "\n The Sum of Entered Numbers Until You Entered -99 is: " << SumNumbers_UntilEntering_minus99();
	cout << "\n";

	return 0;
}