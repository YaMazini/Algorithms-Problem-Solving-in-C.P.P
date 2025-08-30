#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(const short &From, const short&To)
{
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Arr[3][3], const int& Rows, const int& Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Arr[3][3], const int& Rows, const int& Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << Arr[i][j] << "\t";
        }
        cout << "\n";
    }
}



int main()
{
    srand((unsigned)time(NULL));

    int Arr[3][3];
    FillMatrixWithRandomNumbers(Arr, 3, 3);

    cout << " The following is a 3*3 random matrix: \n";
    PrintMatrix(Arr, 3, 3);


    return 0;
}