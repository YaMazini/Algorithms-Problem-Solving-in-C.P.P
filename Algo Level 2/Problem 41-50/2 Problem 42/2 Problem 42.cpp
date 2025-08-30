#include <iostream>
using namespace std;

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

int OddNumbersCount(int Arr[100], int ArrLength)
{
	int Counter = 0;
	for (int i = 0; i < ArrLength; i++)
	{
		if (Arr[i] % 2 != 0)
			Counter++;
	}

	return Counter;
}

void FillArrayWithRandomNumbers(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		Arr[i] = RandomNumber(1, 100);
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
	ArrLength = ReadPositiveNumber("Please enter the number of elements: ");

	FillArrayWithRandomNumbers(Arr, ArrLength);

	cout << "\n Array Elements: ";
	PrintArray(Arr, ArrLength);

	cout << "\n Odd Numbers count is: " << OddNumbersCount(Arr, ArrLength) << "\n";
	

	return 0;
}