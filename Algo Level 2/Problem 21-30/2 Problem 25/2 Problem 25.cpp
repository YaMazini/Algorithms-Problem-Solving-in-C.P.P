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

int GetMinNumberInArray(int Arr[100], int ArrLength)
{
    int MinNum = Arr[0];

    for (int i = 0; i < ArrLength; i++)
    {
        if (Arr[i] < MinNum)
            MinNum = Arr[i];
    }

    return MinNum;
}

void PrintArrayWithMinNum(int Arr[100], int ArrLength)
{
    cout << "\n Array Elements: ";
    for (int i = 0; i < ArrLength; i++)
    {
        cout << Arr[i] << " ";
    }

    cout << "\n Min Number is: " << GetMinNumberInArray(Arr, ArrLength) << "\n";
}



int main()
{
    srand((unsigned)time(NULL));

    int Arr[100], ArrLength = 0;
    ArrLength = ReadPositiveNumber("Please enter number of elements: ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    PrintArrayWithMinNum(Arr, ArrLength);


    return 0;
}