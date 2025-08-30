#include <iostream>
using namespace std;

void PrintLettersFromA_ToZ()
{
    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << "\n";
    }
}


int main()
{
    PrintLettersFromA_ToZ();

    return 0;
}