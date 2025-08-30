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
    cout << "\n Array Elements: ";
    for (int i = 0; i < ArrLength; i++)
    {
        cout << Arr[i] << " ";
    }

    cout << "\n";
}



int main()
{
    srand((unsigned)time(NULL));

    int Arr[100], ArrLength;
    ArrLength = ReadPositiveNumber("Please enter number of elements: ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    PrintArray(Arr, ArrLength);


    return 0;
}