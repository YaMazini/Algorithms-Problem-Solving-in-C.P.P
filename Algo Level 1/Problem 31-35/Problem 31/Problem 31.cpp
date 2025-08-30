
#include <iostream>
using namespace std;


int ReadNumber()
{
	int Number;
	cout << "Please Enter a Number: ", cin >> Number;
	cout << "\n";

	return Number;
}

void PowerOf_2_3_4(int Number)
{
	int N2, N3, N4;
	N2 = Number * Number;
	N3 = Number * Number * Number;
	N4 = Number * Number * Number * Number;

	cout << Number << "^2" << ": " << N2 << endl;
	cout << Number << "^3" << ": " << N3 << endl;
	cout << Number << "^4" << ": " << N4 << endl;
}


int main()
{
	PowerOf_2_3_4(ReadNumber());

	return 0;
}