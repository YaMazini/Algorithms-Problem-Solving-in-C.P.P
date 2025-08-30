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

float CalculateFinalBill(float BillAmount, float RCh, float ST)
{
    float TotalBill;

    BillAmount = BillAmount + (BillAmount * RCh);
    TotalBill = BillAmount + (BillAmount * ST);

    return TotalBill;
}


int main()
{
    float BillAmount = ReadPositiveNumber("Please Enter the Bill Value: $");
    float RestaurantCharges = 0.1;
    float SalesTax = 0.16;


    cout << " \n The Final Bill is: $" << CalculateFinalBill(BillAmount, RestaurantCharges, SalesTax);
    cout << "\n";

    return 0;
}