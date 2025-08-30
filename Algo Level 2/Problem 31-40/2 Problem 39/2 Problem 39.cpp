#include <iostream>
using namespace std;

enum enPrimeNotPrime{Prime = 1, NotPrime = 2};


int ReadPositiveNumber(string Message)
{
    int Number = 0;
	do
	{
		cout << Message;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int RandomNumber(const int From, const int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		Arr[i] = RandomNumber(1, 100);
	}
}

enPrimeNotPrime CheckPrime(int Number)
{
	if (Number == 1)
		return enPrimeNotPrime::NotPrime;

	else if (Number == 2 || Number == 3)
		return enPrimeNotPrime::Prime;

	else if (Number % 2 == 0)
		return enPrimeNotPrime::NotPrime;

	for (int i = 3; i * i <= Number; i += 2)
	{
		if (Number % i == 0)
			return enPrimeNotPrime::NotPrime;

	}
	
	return enPrimeNotPrime::Prime;
}

void AddArrayElement(int Arr[100], int &ArrLength, int Number)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number;
}

void CopyArrayElement(int ArrSource[100], int ArrDestination[100], int ArrSourceLength, int &ArrDestinationLength)
{
	for (int i = 0; i < ArrSourceLength; i++)
	{
		if (CheckPrime(ArrSource[i]) == enPrimeNotPrime::Prime)
		{
			AddArrayElement(ArrDestination, ArrDestinationLength, ArrSource[i]);
		}
	}
}

void PrintArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}



int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], ArrLength = 0;
	ArrLength = ReadPositiveNumber("Please enter the number of arrays: ");

	FillArrayWithRandomNumbers(Arr, ArrLength);

	int Arr2[100], Arr2Length = 0;
	CopyArrayElement(Arr, Arr2, ArrLength, Arr2Length);


	cout << "\n Array 1 elements: \n";
	PrintArray(Arr, ArrLength);

	cout << "\n Array 2 Prime Numbers: \n";
	PrintArray(Arr2, Arr2Length);


    return 0;
}