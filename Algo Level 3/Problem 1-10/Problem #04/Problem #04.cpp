#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(const short& From, const short& To)
{
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Arr[3][3], const short& Rows, const short& Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Arr[3][3], const short& Rows, const short& Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << Arr[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n";
}

int SumOfCol(int Arr[3][3], const short& Rows, const short& ColNumber)
{
    int Sum = 0;
    for (int i = 0; i < Rows; i++)
    {
        Sum += Arr[i][ColNumber];
    }

    return Sum;
}

void PrinteEachColSum(int Arr[3][3], const short& Rows, const short& Cols)
{
    for (int i = 0; i < Cols; i++)
    {
        printf(" Col %d Sum = %d \n", i + 1, SumOfCol(Arr, 3, i));
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int Arr[3][3], SumArr[3];
    FillMatrixWithRandomNumbers(Arr, 3, 3);

    cout << "The Following is a 3*3 random matrix: \n";
    PrintMatrix(Arr, 3, 3);

    cout << "The Following are the sum of each col in the matrix: \n";
    PrinteEachColSum(Arr, 3, 3);


    return 0;
}