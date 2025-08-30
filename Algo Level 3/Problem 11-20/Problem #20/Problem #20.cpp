#include <iostream>
#include <iomanip>
using namespace std;

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

bool IsPalindromeMatrix(int Matrix[3][3], const short& Rows, const short& Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
                return false;
        }
    }

    return true;
}


int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {1,2,1},
                          {5,5,5},
                          {7,3,7}
                        };

    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsPalindromeMatrix(Matrix1, 3, 3))
        cout << " Yes: Matrix is Palindrome! \n";

    else
        cout << " No: Matrix is NOT Palindrome! \n";


    return 0;
}
