#include <iostream>
#include <iomanip>
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
            Arr[i][j] = RandomNumber(0, 1);
        }
    }
}

void PrintMatrix(int Arr[3][3], const short& Rows, const short& Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << Arr[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

short CountNumberInMatrix(int Arr[3][3], const short& Rows, const short& Cols, short Number)
{
    int NumberCounter = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Arr[i][j] == Number)
                NumberCounter++;
        }
    }

    return NumberCounter;
}

bool IsSparseMatrix(int Arr[3][3], const short& Rows, const short& Cols)
{
    short MatrixSize = (Rows * Cols);
    short ZeroCounter = CountNumberInMatrix(Arr, Rows, Cols, 0);

    return (ZeroCounter > MatrixSize / 2);
}

string GetSparseCheckingResult(bool IsSparceMatrix)
{
    return (IsSparceMatrix == true) ? "Sparse!" : "NOT Sparse!";
}


int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix, 3, 3);

    cout << " It is " << GetSparseCheckingResult(IsSparseMatrix(Matrix, 3, 3)) << endl;


    return 0;
}