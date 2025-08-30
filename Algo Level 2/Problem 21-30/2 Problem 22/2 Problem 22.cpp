#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message, cin >> Number;

    } while (Number <= 0);

    return Number;
}

void ReadArray(int arr[100], int& arrLength)
{
    arrLength = ReadPositiveNumber("Please enter the number of elements you want to store: ");

    cout << " Enter array elements: \n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "]: ", cin >> arr[i];
    }
    cout << "\n";
}

int TimesRepeated(int arr[100], int arrLength, int NumToCheck)
{
    int counter = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == NumToCheck)
            counter++;
    }

    return counter;
}

void PrintArrayAndRepetitions(int arr[100], int arrLength, int NumToCheck)
{
    int RepeatedTimes = TimesRepeated(arr, arrLength, NumToCheck);

    cout << "\n Original Array: ";
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n " << NumToCheck << " is repeated "
        << RepeatedTimes
        << " time(s)!\n";
}



int main()
{
    int arr[100], arrLength, NumToCheck;

    ReadArray(arr, arrLength);

    NumToCheck = ReadPositiveNumber("Please enter the number you want to check: ");

    PrintArrayAndRepetitions(arr, arrLength, NumToCheck);


    return 0;
}