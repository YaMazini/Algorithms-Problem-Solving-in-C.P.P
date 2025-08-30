#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int Arr[3][3], const short& Rows, const int& Cols)
{
    short Counter = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Counter++;
            Arr[i][j] = Counter;
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

void GetTransposedMatrix(int TransposedArr[3][3], int Arr[3][3], const short& Rows, const short& Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            TransposedArr[i][j] = Arr[j][i];
        }
    }
}


int main()
{
    int Arr[3][3], TransposedArr[3][3];
    FillMatrixWithOrderedNumbers(Arr, 3, 3);

    cout << "The Following is a 3*3 ordered matrix: \n";
    PrintMatrix(Arr, 3, 3);

    cout << "The Following is a 3*3 Transposed matrix: \n";
    GetTransposedMatrix(TransposedArr, Arr,3, 3);
    PrintMatrix(TransposedArr, 3, 3);


    return 0;
}