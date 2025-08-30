#include <iostream>
#include <string>
using namespace std;


int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message, cin >> Number;

	} while (Number <= 0);

	return Number;
}

int SumOfNumberDigits(int Number)
{
	int Sum = 0; 
	int Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;

		Sum += Remainder;
	}

	return Sum;
}

void PrintSumOfNumberDigits(int Number)
{
	cout << "\n The Sum of " << Number << " digits is: " << SumOfNumberDigits(Number);
	cout << "\n";
}



int main()
{
	PrintSumOfNumberDigits(ReadPositiveNumber("Please enter a positive number: "));


	return 0;
}