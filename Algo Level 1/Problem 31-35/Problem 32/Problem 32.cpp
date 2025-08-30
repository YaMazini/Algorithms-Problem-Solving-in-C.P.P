
#include <iostream>
using namespace std;

void ReadNumbers(int& Number, int& M)
{
	cout << "Please Enter The value of Number: ", cin >> Number;
	cout << "Please Enter The value of M: ", cin >> M;
	cout << "\n";
}

int PowerOf_M(int Number, int M)
{
	if (M == 0)
		return 1;

	int Product = 1;
	for (int i = 1; i <= M; i++)
	{
		Product *= Number;
	}

	return Product;
}



int main()
{
	int Number, M;

	ReadNumbers(Number, M);
	cout << Number << "^" << M << " = ";
	cout << PowerOf_M(Number, M) << "\n";

	return 0;
}      //code cant work here, sir lchi blasa akhra hhhh!