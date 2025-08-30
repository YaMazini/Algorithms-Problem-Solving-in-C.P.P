#include <iostream>
#include <iomanip>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    cout << Message;
    cin >> Number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Wrong Inputs! Please enter a number: ";
        cin >> Number;
    }
    cout << "\n";

    return Number;
}

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
            cout << setw(3) << Arr[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool IsNumberInMatrix(int Arr[3][3], const short& Rows, const short& Cols, const short& Number)
{
    
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Number == Arr[i][j])
                return true;
        }
    }

    return false;
}


int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix, 3, 3);

    short Number = ReadPositiveNumber("Please enter the number to look for in matrix: ");
    
    if (IsNumberInMatrix(Matrix, 3, 3, Number))
        cout << " Yes it is there! \n";

    else
        cout << " No its NOT there! \n";


    return 0;
}