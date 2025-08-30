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

bool IsIdentityMatrix(int Arr[3][3], const short& Rows, const short& Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if ((i != j) && (Arr[i][j] != 0))
                return false;

            else if ( (i == j) && (Arr[i][j] != 1) )
                return false;
        }
    }

    return true;
}

string GetIdentityResult(const bool IsIdentityMatrix)
{
    return (IsIdentityMatrix == true) ? "Identity!" : "NOT Identity!";
}

void PrintIdentityResult(int Arr[3][3], const short& Rows, const short& Cols)
{
    cout << " Matrix is " << GetIdentityResult(IsIdentityMatrix(Arr, Rows, Cols)) << endl;
}



int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix, 3, 3);

    PrintIdentityResult(Matrix, 3, 3);

    return 0;
}