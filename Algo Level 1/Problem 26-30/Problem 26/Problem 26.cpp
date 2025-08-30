
#include <iostream>
using namespace std;


int ReadNumber()
{
    int N;
    cout << "Please Enter a Number: ", cin >> N;
    return N;
}


void PrintRangeFrom1ToN_UsingForLoop(int N)
{
    cout << " For Loop::Numbers from 1 to " << N << ": \n";
    for (int i = 1; i <= N; i++)
    {
        cout << i << "\n";
    }

    cout << "\n";
}


void PrintRangeFrom1ToN_UsingDoWhileLoop(int N)
{
    cout << " Do While Loop::Numbers from 1 to " << N << ": \n";
    
    int i = 1;
    do 
    {
        cout << i << "\n";
        i++;
    } while (i <= N);

    cout << "\n";
}


void PrintRangeFrom1ToN_UsingWhileLoop(int N)
{
    cout << " While Loop::Numbers from 1 to " << N << ": \n";
    
    int i = 1;
    while (i <= N)
    {
        cout << i << "\n";
        i++;
    }

    cout << "\n";
}


int main()
{
    int N = ReadNumber();


    PrintRangeFrom1ToN_UsingForLoop(N);

    PrintRangeFrom1ToN_UsingDoWhileLoop(N);

    PrintRangeFrom1ToN_UsingWhileLoop(N);


    return 0;
}                   //Code cant run in this folder, sir lchi folder khor hhhh