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

void PrintArray(int Arr[100], int ArrLength)
{
    cout << " Array Elements: ";
    for (int i = 0; i < ArrLength; i++)
    {
        cout << Arr[i] << " ";
    }

}

void CopyArray(int Arr[100], int Arr_2[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        Arr_2[i] = Arr[i];
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int Arr[100], Arr_2[100], ArrLength = 0;
    ArrLength = ReadPositiveNumber("Please enter number of elements: ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    PrintArray(Arr, ArrLength);

    CopyArray(Arr, Arr_2, ArrLength);
    cout << "\n Array 2 after copy, ";
    PrintArray(Arr_2, ArrLength);

    cout << "\n";

    return 0;
}