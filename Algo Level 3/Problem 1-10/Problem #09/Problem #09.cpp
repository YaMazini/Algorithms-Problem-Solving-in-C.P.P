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

void PrintMiddleRow(int Arr[3][3], const short& Rows, const short& Cols)
{
    short MiddleRow = Rows / 2;

    for (short i = 0; i < Cols; i++)
    {
        printf(" %0*d\t", 2, Arr[MiddleRow][i]);
    }

    cout << "\n\n";
}

void PrintMiddleCol(int Arr[3][3], const short& Rows, const short& Cols)
{
    short MiddleCol = Cols / 2;
    for (short i = 0; i < Rows; i++)
    {
        printf(" %0*d\t", 2, Arr[i][MiddleCol]);
    }
    cout << "\n\n";
}


int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);

    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "Middle Row of Matrix1 is: \n";
    PrintMiddleRow(Matrix1, 3, 3);

    cout << "Middle Col of Matrix1 is: \n";
    PrintMiddleCol(Matrix1, 3, 3);


    return 0;
}