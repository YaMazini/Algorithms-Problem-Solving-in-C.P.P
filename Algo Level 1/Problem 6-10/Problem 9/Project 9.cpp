

#include <iostream>
using namespace std;


struct stNumbers 
{
	int Number1;
	int Number2;
	int Number3;
};

stNumbers ReadNumbers()
{
	stNumbers Numbers;
	cout << "Please Enter Number 1: ", cin >> Numbers.Number1;
	cout << "Please Enter Number 2: ", cin >> Numbers.Number2;
	cout << "Please Enter Number 3: ", cin >> Numbers.Number3;

	return Numbers;
}

int GetSumNumbers(stNumbers Numbers)
{
	return Numbers.Number1 + Numbers.Number2 + Numbers.Number3;
}

void PrintNumbers(int Sum)
{
	cout << "The Sum Of The Three Numbers is: " << Sum << "\n";
}



int main()
{

	PrintNumbers(GetSumNumbers(ReadNumbers()));

	return 0;
}
