#include <iostream>
using namespace std;

void AddArrayElement(int Arr[100], int& ArrLength, int Number)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number;
}

short FindNumberInPositionInArray(int Arr[100], int ArrLength, int Number)
{
	for (int i = 0; i < ArrLength; i++)
	{
		if (Arr[i] == Number)
			return i;
	}

	return -1;
}

bool IsNumberInArray(int Arr[100], int ArrLength, int Number)
{
	return FindNumberInPositionInArray(Arr, ArrLength, Number) != -1;
}

void CopyDistinctNumbersToArray(int ArrSource[100], int ArrDestination[100], int ArrSourceLength, int ArrDestinationLength)
{
	for (int i = 0; i < ArrSourceLength; i++)
	{
		if (!IsNumberInArray(ArrDestination, ArrDestinationLength, ArrSource[i]))
			AddArrayElement(ArrDestination, ArrDestinationLength, ArrSource[i]);
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

	int Arr[100] = { 10, 10, 10, 50, 50, 70, 70, 70, 70, 90 };
	int ArrLength = 10;
	int Arr2[100], Arr2Length = 0;

	CopyDistinctNumbersToArray(Arr, Arr2, ArrLength, Arr2Length);

	cout << "\n Array 1 elements: \n";
	PrintArray(Arr, ArrLength);

	cout << "\n Array 2 Distinct elements: \n";
	PrintArray(Arr2, Arr2Length);


	return 0;
}