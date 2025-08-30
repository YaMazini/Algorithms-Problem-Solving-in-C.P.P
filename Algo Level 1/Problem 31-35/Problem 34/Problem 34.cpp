#include <iostream>
using namespace std;

int ReadTotalSales()
{
	int TotalSales;
	cout << "Please Enter Your amount of Total Sales: $", cin >> TotalSales;
	cout << "\n";

	return TotalSales;
}

int GetCommissionPercentage(int TotalSales)
{
	if (TotalSales >= 1000000)
		return 1;

	else if (TotalSales >= 500000 && TotalSales < 1000000)
		return 2;

	else if (TotalSales >= 100000 && TotalSales < 500000)
		return 3;

	else if (TotalSales >= 50000 && TotalSales < 100000)
		return 5;

	else
		return 0;
}

float CalculateTotalCommission(int TotalSales)
{
	return TotalSales * GetCommissionPercentage(TotalSales) / 100;
}


int main()
{
	int TotalSales = ReadTotalSales();

	cout << "\n Commission Percentage From The Total Sales: " << GetCommissionPercentage(TotalSales) << "%" << "\n";
	cout << " Total Commission From The Total Sales: $" << CalculateTotalCommission(TotalSales) << "\n";

	return 0;
}