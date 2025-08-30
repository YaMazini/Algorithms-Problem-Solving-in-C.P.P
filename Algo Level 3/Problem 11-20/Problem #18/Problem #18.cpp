#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(const short& From, const short& To)
{
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], const short& Rows, const short& Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Matrix[3][3], const short& Rows, const short& Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << Matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool IsNumberInMatrix(int Matrix[3][3], const short& Rows, const short& Cols, const short& Number)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Number == Matrix[i][j])
                return true;
        }
    }

    return false;
}

void PrintIntersectedNumber(int Matrix1[3][3], int Matrix2[3][3], const short& Rows, const short& Cols)
{
    short Number = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Number = Matrix1[i][j];
            if (IsNumberInMatrix(Matrix2, Rows, Cols, Number))
                cout << Matrix1[i][j] << "\t";
        }
    }

    cout << "\n";
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

    cout << "Intersected Numbers are: \n";
    PrintIntersectedNumber(Matrix1, Matrix2, 3, 3);


    return 0;
}