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
}


int main()
{
    int Arr[3][3];
    FillMatrixWithOrderedNumbers(Arr, 3, 3);

    cout << "The Following is a 3*3 ordered matrix: \n";
    PrintMatrix(Arr, 3, 3);


    return 0;
}