
#include <iostream>
using namespace std;

struct stNumbers 
{
	int Number1;
	int Number2;
};

stNumbers ReadNumbers()
{
	stNumbers Numbers;
	cout << "Please Enter Number 1: ", cin >> Numbers.Number1;
	cout << "Please Enter Number 2: ", cin >> Numbers.Number2;

	return Numbers;
}

int CheckMaxNum(stNumbers Numbers)
{
	if (Numbers.Number1 > Numbers.Number2)
		return Numbers.Number1;
	else
		return Numbers.Number2;
}

void PrintMaxNum(stNumbers Numbers)
{
	cout << "\tThe Max Number is: " << CheckMaxNum(Numbers) << "\n";
}


int main()
{
	stNumbers Numbers = ReadNumbers();
	PrintMaxNum(Numbers);
	
	return 0;
}