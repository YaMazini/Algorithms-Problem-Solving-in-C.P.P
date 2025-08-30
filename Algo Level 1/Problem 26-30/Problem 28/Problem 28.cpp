

#include <iostream>
using namespace std;

enum enOddEven {Odd = 1, Even = 2};


int ReadNumber()
{
    int N;
    cout << "Please Enter a Number: ", cin >> N;
    cout << "\n";

    return N;
}

enOddEven CheckOddOrEven(int N)
{
    if (N % 2 != 0)
        return enOddEven::Odd;
    
    else
        return enOddEven::Even;
}

int SumOddNumbersInRange_1_To_N_UsingForLoop(int N)
{
    int sum = 0;
    for (int i = 0; i <= N; i++)
    {

        if (CheckOddOrEven(i) == 1)
        {
            sum += i;
        }

    }

    return sum;
}

int SumOddNumbersInRange_1_To_N_UsingDoWhileLoop(int N)
{
    int i = 0;
    int sum = 0; 

    do
    {

        if (CheckOddOrEven(i) == 1)
        {
            sum += i;
        }
        i++;

    } while (i <= N);

    return sum;
}

int SumOddNumbersInRange_1_To_N_UsingWhileLoop(int N)
{
    int i = 0;
    int sum = 0;

    while (i <= N)
    {

        if (CheckOddOrEven(i) == 1)
        {
            sum += i;
        }
        i++;

    }

    return sum;
}


void PrintResults(int N)
{
    cout << " ForLoop::The Sum of Odd numbers from 1 to " << N << ": ";
    cout << SumOddNumbersInRange_1_To_N_UsingForLoop(N) << endl;


    cout << "\n Do While Loop::The Sum of Odd numbers from 1 to " << N << ": ";
    cout << SumOddNumbersInRange_1_To_N_UsingDoWhileLoop(N) << endl;


    cout << "\n While Loop::The Sum of Odd numbers from 1 to " << N << ": ";
    cout << SumOddNumbersInRange_1_To_N_UsingWhileLoop(N) << endl;
}



int main()
{
    int N = ReadNumber();

    PrintResults(N);


    return 0;
}