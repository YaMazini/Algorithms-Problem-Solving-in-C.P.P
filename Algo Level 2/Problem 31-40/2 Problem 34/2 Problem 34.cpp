#include <iostream>
using namespace std;

int RandomNumber(const int From, const int To)
{
	return rand() % (To - From + 1) + From;
}

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

void FillArrayWithRandomNumbers(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		Arr[i] = RandomNumber(1, 100);
	}
}

short FindNumberPositionInArray(int Arr[100], int ArrLength, int Number)
{
    for (int i = 0; i < ArrLength; i++)
	{
	    if (Number == Arr[i])
			return i;
	}

	return -1;
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
	cout << "\n Array Elements: \n";
	PrintArray(Arr, ArrLength);


	int Number = 0;
	short Position, Order;

	Number = ReadPositiveNumber("\nPlease enter a number to search for: ");
	Position = FindNumberPositionInArray(Arr, ArrLength, Number);
	Order = Position + 1;

	cout << " Number you are looking for is: " << Number << "\n";
	if (Position != -1)
	{
		cout << " The number found at position: " << Position << "\n";
		cout << " The Number found its order: " << Order << "\n";
	}

	else
	{
		cout << " The Number is not found :(\n";
	}


	return 0;
}