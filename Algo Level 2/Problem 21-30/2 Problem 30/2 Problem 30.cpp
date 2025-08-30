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

void SumOfTwoArrays(int Arr[100], int Arr_2[100], int ArrLength, int ArrSum[100])
{
    for (int i = 0; i < ArrLength; i++)
    {
        ArrSum[i] = Arr[i] + Arr_2[i];
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

    int Arr[100], Arr_2[100], ArrLength = 0;
    ArrLength = ReadPositiveNumber("Please enter number of elements: ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    FillArrayWithRandomNumbers(Arr_2, ArrLength);

    int ArrSum[100];

    SumOfTwoArrays(Arr, Arr_2, ArrLength, ArrSum);

    cout << "\n Array 1 elements: \n";
    PrintArray(Arr, ArrLength);

    cout << "\n Array 2 elements: \n";
    PrintArray(Arr_2, ArrLength);

    cout << "\n Sum of Array1 and Array2 elements: \n";
    PrintArray(ArrSum, ArrLength);
    

    return 0;
}