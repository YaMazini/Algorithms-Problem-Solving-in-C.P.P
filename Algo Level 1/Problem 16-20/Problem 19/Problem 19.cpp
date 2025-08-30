
#include <iostream>
using namespace std;

float ReadDiametre()
{
    float D;
    cout << "Please Enter The value of D: ", cin >> D;
    cout << "\n";

    return D;
}

float CalculateTheCircleAreaByDiametre(float D)
{
    const float PI = 3.14;
    return (PI * pow(D, 2)) / 4;
}

void PrintResult(float Area)
{
    cout << "The Circle Area is: " << Area << "\n";
}


int main()
{

    PrintResult(CalculateTheCircleAreaByDiametre(ReadDiametre()));

    return 0;
}

