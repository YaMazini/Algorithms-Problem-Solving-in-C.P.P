

#include <iostream>
using namespace std;


enum enPassFail{Pass = 1, Fail = 2};

int ReadMark()
{
	int Mark;
	cout << "Please Enter Your Mark: ", cin >> Mark;
	return Mark;
}

enPassFail Checking(int Mark)
{
	if (Mark >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void PrintResult(int Mark)
{
	if (Checking(Mark) == enPassFail::Pass)
		cout << " You Passed\n";

	else
		cout << " You Failed\n";
}



int main()
{

	PrintResult(ReadMark());

	return 0;
}