
#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
    float Number;
    do
    {
        cout << Message, cin >> Number;

    } while (Number <= 0);

    return Number;
}

float CalculateRemainder(float CashPaid, float TotalBill)
{
    return CashPaid - TotalBill;
}


int main()
{
    float TotalBill = ReadPositiveNumber("Please Enter The Total Bill: $");
    float CashPaid = ReadPositiveNumber("Please Enter the CashPaid: $");
    

    cout << "\nTotal Bill: " << TotalBill << "\n";
    cout << "Cash Paid: " << CashPaid << "\n";


    cout << "\n\tThe Remainder to be paid back is: " << CalculateRemainder(CashPaid, TotalBill);
    cout << "\n";

    return 0;
}