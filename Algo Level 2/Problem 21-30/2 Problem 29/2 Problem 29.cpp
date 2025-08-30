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
    for (int i = 0; i < ArrLength; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

bool IsPrime(int Number)
{
    if (Number <= 1)
        return false;

    else if (Number == 2 || Number == 3)
        return true;

    else if (Number % 2 == 0)
        return false;

    int SQRTofNumber = sqrt(Number);
    for (int i = 3; i <= SQRTofNumber; i += 2)
    {
        if (Number % i == 0)
            return false;
    }

    return true;
}

void CopyPrimeNumbersInArray(int Arr[100], int Arr_2[100], int ArrLength, int &Arr_2Length)
{
    Arr_2Length = 0;

    for (int i = 0; i < ArrLength; i++)
    {
        if (IsPrime(Arr[i]))
        {
            Arr_2[Arr_2Length] = Arr[i];
            Arr_2Length++;
        }
    }
}



int main()
{
    srand((unsigned)time(NULL));

    int Arr[100], Arr_2[100], ArrLength = 0, Arr_2Length = 0;
    ArrLength = ReadPositiveNumber("Please enter number of elements: ");

    FillArrayWithRandomNumbers(Arr, ArrLength);
    CopyPrimeNumbersInArray(Arr, Arr_2, ArrLength, Arr_2Length);

    cout << "\n Array Elements: \n";
    PrintArray(Arr, ArrLength);

    cout << "\n Prime Numbers in Array2: \n";
    PrintArray(Arr_2, Arr_2Length);

    return 0;
}