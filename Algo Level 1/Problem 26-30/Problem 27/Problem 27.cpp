

#include <iostream>
using namespace std;


int ReadNumber()
{
    int N;
    cout << "Please Enter a Number: ", cin >> N;
    cout << "\n";

    return N;
}

void PrintRangeFrom_N_To1_UsingForLoop(int N)
{
    cout << " ForLoop::Number from " << N << " to 1: \n";

    for (int i = N; i >= 1; i--)
    {
        cout << i << "\n";
    }

    cout << "\n";
}

void PrintRangeFrom_N_To1_UsingDoWhileLoop(int N)
{
    cout << " Do While Loop::Number from " << N << " to 1: \n";

    int i = N;
    do
    {
        cout << i << "\n";
        i--;
    } while (i >= 1);

    cout << "\n";
}

void  PrintRangeFrom_N_To1_UsingWhileLoop(int N)
{
    cout << " While Loop::Number from " << N << " to 1: \n";

    int i = N;
    while (i >= 1)
    {
        cout << i << "\n";
        i--;
    }

    cout << "\n";
}


int main()
{
    int N = ReadNumber();

    PrintRangeFrom_N_To1_UsingForLoop(N);
    PrintRangeFrom_N_To1_UsingDoWhileLoop(N);
    PrintRangeFrom_N_To1_UsingWhileLoop(N);

    return 0;
}

