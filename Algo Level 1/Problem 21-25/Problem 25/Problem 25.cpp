

#include <iostream>
using namespace std;

int ReadAge()
{
    int Age;
    cout << "Please Enter Your Age: ", cin >> Age;
    cout << "\n";

    return Age;
}

bool IsValidAge(int Age, int From, int To)
{
    return (Age >= From && Age <= To);
}

void PrintResult(int Age)
{
    while (!IsValidAge(Age, 18, 45))
    {
        cout << "Invalid Age! Please Enter Your Age: ", cin >> Age;
    }

    cout << "\n Valid Age!\n";
}


int main()
{

    PrintResult(ReadAge());

    return 0;
}