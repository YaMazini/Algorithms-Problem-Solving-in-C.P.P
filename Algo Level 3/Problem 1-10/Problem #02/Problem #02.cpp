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
    for (int i = 0; i < Rows;i++)
    {
        for (int j = 0; j < Cols;j++)
        {
            cout << setw(3) << Arr[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n";
}


int SumOfRow(int Arr[3][3], const short& RowNumber, const short& Cols)
{
    int Sum = 0;

    for (int j = 0; j < Cols; j++)
    {
        Sum += Arr[RowNumber][j];
    }

    return Sum;
}

void PrintSumOfRows(int Arr[3][3], const short& Rows, const short& Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        printf(" Row %d Sum = %d \n", i + 1, SumOfRow(Arr, i, Cols));
    }
}



int main()
{
    srand((unsigned)time(NULL));
    
    int Arr[3][3];
    FillMatrixWithRandomNumbers(Arr, 3, 3);

    cout << "The following is a 3*3 random matrix: \n";
    PrintMatrix(Arr, 3, 3);

    cout << "The following are the sum of each row in the matrix: \n";
    PrintSumOfRows(Arr, 3, 3);


    return 0;
}