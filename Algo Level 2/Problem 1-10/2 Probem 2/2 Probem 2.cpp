#include <iostream>
#include <cmath>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

int ReadPositiveNumber(string Message)
{
	int N;
	do
	{
		cout << Message, cin >> N;

	} while (N <= 0);

	return N;
}

enPrimeNotPrime CheckPrime(int i)
{
	int M = round(i / 2);


	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (i % Counter == 0)
			return enPrimeNotPrime::NotPrime;
	}

	return enPrimeNotPrime::Prime;
}

void PrintPrimeNumbersInRangeN(int Number)
{
	cout << "\n Prime Numbers from 1 to " << Number << " are: \n";

	for (int i = 1; i <= Number; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
			cout << i << "\n";
	}
}


int main()
{
	int Number = ReadPositiveNumber("Please enter a positive number: ");

	PrintPrimeNumbersInRangeN(Number);

	return 0;
}