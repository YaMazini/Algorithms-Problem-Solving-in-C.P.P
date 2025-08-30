#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(const short& From, const short& To)
{
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Arr[3][3], const short& Rows, const short& Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Arr[3][3], const short& Rows, const short& Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << Arr[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n";
}

int SumOfCol(int Arr[3][3], const short& Rows, const short& ColNumber)
{
    int Sum = 0;
    for (int i = 0; i < Rows; i++) 
    {
        Sum += Arr[i][ColNumber];
    }

    return Sum;
}

void GetArrayFromColsSum(int SumArr[3], int Arr[3][3], const short& Rows, const short& Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        SumArr[i] = SumOfCol(Arr, Rows, i);
    }
}

void PrintArrayOfColsSum(int SumArr[3], const short& Length)
{
    for (int i = 0; i < Length; i++)
    {
        printf(" Cols %d Sum = %d \n", i + 1, SumArr[i]);
    }
}



int main()
{
    srand((unsigned)time(NULL));

    int Arr[3][3], SumArr[3];
    FillMatrixWithRandomNumbers(Arr, 3, 3);

    cout << "The Following is a 3*3 random matrix: \n";
    PrintMatrix(Arr, 3, 3);

    GetArrayFromColsSum(SumArr, Arr, 3, 3);
    cout << "The Following are the sum of each cols in the matrix: \n";
    PrintArrayOfColsSum(SumArr, 3);


    return 0;
}