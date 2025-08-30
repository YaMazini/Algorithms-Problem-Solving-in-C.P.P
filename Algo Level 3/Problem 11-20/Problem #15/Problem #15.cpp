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

short CountNumberInMatrix(int Arr[3][3], const short& Rows, const short& Cols, const short& Number)
{
    short NumberCounter = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Arr[i][j] == Number)
            {
                NumberCounter++;
            }
        }
    }

    return NumberCounter;
}



int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix, 3, 3);

    int Number = ReadPositiveNumber("Enter the number to count in matrix: ");
    printf("Number %d count in matrix is: %d \n", Number, CountNumberInMatrix(Matrix, 3, 3, Number));


    return 0;
}