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

void FillArrayFrom1ToN(int Arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        Arr[i] = RandomNumber(1, 100);
    }
}

void CopyInReverseOrderArray(int ArrSource[100], int ArrDestination[100], int ArrLength)
{
    int counter = ArrLength - 1;
    for (int i = 0; i < ArrLength; i++)
    {
        ArrDestination[i] = ArrSource[counter];
        counter--;
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


    FillArrayFrom1ToN(Arr, ArrLength);

    CopyInReverseOrderArray(Arr, Arr_2, ArrLength);


    cout << "\n Array 1 elements: \n";
    PrintArray(Arr, ArrLength);

    cout << "\n Array 2 elements after copying array 1 in reversed order: \n";
    PrintArray(Arr_2, ArrLength);
    

    return 0;
}