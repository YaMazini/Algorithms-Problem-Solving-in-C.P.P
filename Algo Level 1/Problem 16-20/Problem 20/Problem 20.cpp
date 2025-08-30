
#include <iostream>
#include <cmath>

using namespace std;


float ReadA()
{
    float A;
    cout << "Please Enter The value of A: ", cin >> A;
    cout << "\n";

    return A;
}

float CalculateTheCircleArea(float A)
{
    float PI = 3.14;
    return (PI * pow(A, 2)) / 4;
}

void PrintResult(float Area)
{
    cout << " The Circle Area is: " << Area << "\n";
}


int main()
{
    PrintResult(CalculateTheCircleArea(ReadA()));

    return 0;
}