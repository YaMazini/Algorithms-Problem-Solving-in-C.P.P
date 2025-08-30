#include <iostream>
#include <ctime>
using namespace std;


int RandomNumber(const short& From, const short& To)
{
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Arr[3][3], const short& Rows, const short& Cols)
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
            printf(" %0*d\t", 2, Arr[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";
}

int SumOfMatrix(int Arr[3][3], const short& Rows, const short& Cols)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Sum += Arr[i][j];
        }
    }

    return Sum;
}

bool IsEqual(int& Number1, int& Number2)
{
    return (Number1 == Number2);
}

string GetEquivilentResult(bool IsEqual)
{
    return (IsEqual == true) ? "Equal" : "NOT Equal";
}

void PrintEquivilentResult(int Arr1[3][3], int Arr2[3][3], const short& Rows, const short& Cols)
{
    int Sum1 = SumOfMatrix(Arr1, Rows, Cols);
    int Sum2 = SumOfMatrix(Arr2, Rows, Cols);

    cout << " Matrices are " << GetEquivilentResult(IsEqual(Sum1, Sum2)) << endl;
}


int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "Matrix2: \n";
    PrintMatrix(Matrix2, 3, 3);

    PrintEquivilentResult(Matrix1, Matrix2, 3, 3);


    return 0;
}