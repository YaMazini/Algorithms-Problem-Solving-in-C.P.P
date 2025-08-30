#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(const short& From, const short& To)
{
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Arr[3][3], const short& Rows, const int& Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int Arr[3][3], const short& Rows, const short& Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3);
            printf(" %0*d\t", 2, Arr[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";
}

int ProductOfTwoNumbers(short Number1, short Number2)
{
    return Number1 * Number2;
}

void GetMatrixFromMul(int Arr1[3][3], int Arr2[3][3], int MulArr[3][3], const short& Rows, const short& Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            MulArr[i][j] = ProductOfTwoNumbers(Arr1[i][j], Arr2[i][j]);
        }
    }
}



int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3], MulMatrix[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "Matrix2: \n";
    PrintMatrix(Matrix2, 3, 3);

    GetMatrixFromMul(Matrix1, Matrix2, MulMatrix, 3, 3);

    cout << "Result: \n";
    PrintMatrix(MulMatrix, 3, 3);


    return 0;
}