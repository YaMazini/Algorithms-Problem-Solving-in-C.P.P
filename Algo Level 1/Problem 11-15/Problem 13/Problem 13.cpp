

#include <iostream>
using namespace std;

void ReadNumbers(int& A, int& B, int& C)
{
    cout << "Please Enter the value of A: ", cin >> A;
    cout << "Please Enter the value of B: ", cin >> B;
    cout << "Please Enter the value of C: ", cin >> C;
}

int MaxOf3Numbers(int A, int B, int C)
{
    int MaxNum;

    if (A > B && A > C)
        MaxNum = A;
    else if (B > A && B > C)     //We can remove B > A!
        MaxNum = B;
    else
        MaxNum = C;

    return MaxNum;
}

void PrintResult(int Max)
{
    cout << "The Max Number is: "  << Max << "\n";
}

int main()
{
    int A, B, C;

    ReadNumbers(A, B, C);
    PrintResult(MaxOf3Numbers(A, B, C));

    return 0;
}

