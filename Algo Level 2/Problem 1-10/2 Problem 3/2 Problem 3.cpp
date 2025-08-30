#include <iostream>
using namespace std;

enum enPerfectNotPerfect { Perfect = 1, NotPerfect = 2 };


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

enPerfectNotPerfect CheckPerfect(int Number)
{
	if (DivisorsSumOfNumber(Number) == Number)
		return enPerfectNotPerfect::Perfect;

	else
		return enPerfectNotPerfect::NotPerfect;
} //We can use a boolean datatype instead of an enum 

void PrintPerfectOrNotPerfect(int Number)
{
	cout << "\t";

	switch (CheckPerfect(Number))
	{

	case enPerfectNotPerfect::Perfect:
		cout << Number << " is Perfect\n";
		break;

	case enPerfectNotPerfect::NotPerfect:
		cout << Number << " is Not Perfect\n";
		break;

	}
}



int main()
{
	int Number = ReadPositiveNumber("Please enter a positive number: ");

	PrintPerfectOrNotPerfect(Number);


	return 0;
}