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

bool IsEqual(short Number1, short Number2)
{
    return (Number1 == Number2);
}

string GetTypicalResult(int Matrix1[3][3], int Matrix2[3][3], const short& Rows, const short& Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (!IsEqual(Matrix1[i][j], Matrix2[i][j]))
                return "NOT Equal";
        }
    }
    
    return "Equal";
}

void PrintTypicalResult(int Matrix1[3][3], int Matrix2[3][3], const short& Rows, const short& Cols)
{
    cout << " Matrices are " << GetTypicalResult(Matrix1, Matrix2, Rows, Cols) << endl;
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

    PrintTypicalResult(Matrix1, Matrix2, 3, 3);


    return 0;
}