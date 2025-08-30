#include <iostream>
using namespace std;

void FillArray(int Arr[100], int &ArrLength)
{
	ArrLength = 6;
	Arr[0] = 10;
	Arr[1] = 20;
	Arr[2] = 30;
	Arr[3] = 30;
	Arr[4] = 20;
	Arr[5] = 10;
}

void AddArrayElement(int Arr[100], int& ArrLength, int Number)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number;
}

void PrintArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}

bool IsPalindromeArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength / 2; i++) // Loop only through the first half (it compare the first half to the second[last] half)
	{
		if (Arr[i] != Arr[ArrLength - i - 1]) // Compare first and last, second and second-last, etc.
		{
			return false; // If "mismatch" found, return immediately (array is NOT a palindrome)
		}
	}
	return true; // If loop completes, array is a palindrome
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], ArrLength = 0;
	FillArray(Arr, ArrLength);

	cout << "\n Array elements: \n";
	PrintArray(Arr, ArrLength);

	if (!IsPalindromeArray(Arr, ArrLength))
		cout << "\n The Array is not Palindrome\n";

	else
		cout << "\n The Array is Palindrome!\n";


	return 0;
}