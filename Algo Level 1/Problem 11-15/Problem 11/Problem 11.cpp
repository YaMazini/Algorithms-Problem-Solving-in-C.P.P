

#include <iostream>
using namespace std;

enum enPassFail {Pass = 1, Fail = 2};

void ReadMarks(int ArrMarks[3])
{
    cout << "Please Enter Mark 1: ", cin >> ArrMarks[0];
    cout << "Please Enter Mark 2: ", cin >> ArrMarks[1];
    cout << "Please Enter Mark 3: ", cin >> ArrMarks[2];
}

int SumOfMarks(int ArrMarks[3])
{
    return ArrMarks[0] + ArrMarks[1] + ArrMarks[2];
}

float AvgOfMarks(int ArrMarks[3])
{
    return (float) SumOfMarks(ArrMarks) / 3;
}

enPassFail CheckingAvg(int ArrMarks[3])
{
    if (AvgOfMarks(ArrMarks) >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void PrintResult(int ArrMarks[3])
{
    float Avg = AvgOfMarks(ArrMarks);
    cout << "Your Average Of Marks is: " << Avg << "\n";

    if (CheckingAvg(ArrMarks) == enPassFail::Pass)
        cout << "\tYou Passed!";
    else
        cout << "\tYou Failed!";
}

int main()
{
    int ArrMarks[3];

    ReadMarks(ArrMarks);
    PrintResult(ArrMarks);

    return 0;
}

