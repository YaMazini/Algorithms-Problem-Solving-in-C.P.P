
#include <iostream>
#include <cmath>
using namespace std;

int ReadAge()
{
    int Age;
    cout << "Please Enter Your Age: ", cin >> Age;
    return Age;
}

bool ValidateNumberInRange(int Number, int from, int to)
{
    return (Number >= from && Number <= to);   //it will return true or false bc it is a boolean datatype
}

void PrintResult(int Age)
{
    if (ValidateNumberInRange(Age, 18, 45))
        cout << Age << " is a valid Age\n";
    else
        cout << Age << " is invalid Age\n";
}


int main()
{
    
    PrintResult(ReadAge());

    return 0;

}