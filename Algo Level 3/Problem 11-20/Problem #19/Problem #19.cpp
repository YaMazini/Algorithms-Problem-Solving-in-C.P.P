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

short GetMinNumberInMatrix(int Matrix[3][3], const short& Rows, const short& Cols)
{
    short MinNumber = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] < MinNumber)
                MinNumber = Matrix[i][j];
        }
    }

    return MinNumber;
}

short GetMaxNumberInMatrix(int Matrix[3][3], const short& Rows, const short& Cols)
{
    short MaxNumber = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] > MaxNumber)
                MaxNumber = Matrix[i][j];
        }
    }

    return MaxNumber;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << " Min Number in Matrix is: " << GetMinNumberInMatrix(Matrix1, 3, 3) << endl;
    cout << " Max Number in Matrix is: " << GetMaxNumberInMatrix(Matrix1, 3, 3) << endl;
    

    return 0;
}