
#include <iostream>
using namespace std;

enum enPrimeNotPrime{ Prime = 1, NotPrime = 2 };


int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message, cin >> Number;

    } while (Number <= 0);

    return Number;
}

enPrimeNotPrime CheckPrimeOrNotPrime(int Number)
{
    if (Number == 1)
        return enPrimeNotPrime::NotPrime;


    else if (Number == 2)
        return enPrimeNotPrime::Prime;


    for (int i = 2; i * i <= Number; i++)
    {
        if (Number % i == 0)
            return enPrimeNotPrime::NotPrime;
    
    }


    return enPrimeNotPrime::Prime;
}


void PrintNumberType(int Number, enPrimeNotPrime PrimeOrNotPrime)
{
    switch (PrimeOrNotPrime)
    {

    case enPrimeNotPrime::Prime:
        cout << "\n " << Number << " is a Prime Number!" << endl;
        break;

    case enPrimeNotPrime::NotPrime:
        cout << "\n " << Number << " is Not Prime Number!" << endl;
        break;

    }
}



int main()
{
    int Number = ReadPositiveNumber("Please Enter a Positive Number: ");

    PrintNumberType(Number, CheckPrimeOrNotPrime(Number));


    return 0;
}