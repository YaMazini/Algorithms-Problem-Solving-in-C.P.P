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

void Swap(int& A, int& B)
{
    int Temp = B;
    B = A;
    A = Temp;
}

void FillArrayFrom1ToN(int Arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        Arr[i] = i + 1;
    }
}

void ShuffleArray(int Arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        int Index1 = RandomNumber(1, ArrLength) - 1;
        int Index2 = RandomNumber(1, ArrLength) - 1;

        Swap(Arr[Index1], Arr[Index2]);
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
    ArrLength = ReadPositiveNumber("Please enter number of elements: ");

    FillArrayFrom1ToN(Arr, ArrLength);

    cout << "\n Array Elements before shuffle: \n";
    PrintArray(Arr, ArrLength);

    ShuffleArray(Arr, ArrLength);

    cout << "\n Array Elements after shuffle: \n";
    PrintArray(Arr, ArrLength);


    return 0;
}