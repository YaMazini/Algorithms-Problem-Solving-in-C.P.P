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

int RandomNumber(int From, int To)
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

float GetAvgOfNumbersInArray(int Arr[100], int ArrLength)
{
    int Sum = 0;
    float Avg = 0;

    for (int i = 0; i < ArrLength; i++)
    {
        Sum += Arr[i];
    }

    Avg = (float) Sum / (ArrLength);

    return Avg;
}

void PrintArrayWithAvg(int Arr[100], int ArrLength)
{
    cout << "\n Array Elements: ";
    for (int i = 0; i < ArrLength; i++)
    {
        cout << Arr[i] << " ";
    }

    cout << "\n Average of all numbers is: " << GetAvgOfNumbersInArray(Arr, ArrLength) << "\n";
}



int main()
{
    srand((unsigned)time(NULL));

    int Arr[100], ArrLength = 0;
    ArrLength = ReadPositiveNumber("Please enter number of elements: ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    PrintArrayWithAvg(Arr, ArrLength);


    return 0;
}