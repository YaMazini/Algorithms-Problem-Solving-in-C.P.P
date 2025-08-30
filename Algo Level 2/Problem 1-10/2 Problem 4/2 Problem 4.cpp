#include <iostream>
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

int DivisorsSumOfNumber(int Number)
{
	int Sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
			Sum += i;
	}
	return Sum;
}

bool IsPerfectNumber(int Number)
{
	return Number == DivisorsSumOfNumber(Number);
} // I Used boolean DataType instead of enum DataType!

void PrintPerfectNumbersInRange_1_To_N(int Number)
{
	cout << "\n";

	for (int i = 1; i <= Number; i++)
	{
		if (IsPerfectNumber(i))
			cout << i << " is a Perfect Number\n";
	}
}


int main()
{
	int Number = ReadPositiveNumber("Please enter a positive number: ");

	PrintPerfectNumbersInRange_1_To_N(Number);


	return 0;
}