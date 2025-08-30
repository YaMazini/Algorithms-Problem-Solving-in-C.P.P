#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandomNumber = rand() % (To - From + 1) + From;

    return RandomNumber;
}


int main()
{
    srand((unsigned)time(NULL));

    
    
    return 0;
}