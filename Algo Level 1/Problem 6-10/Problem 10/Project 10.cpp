
#include <iostream>
using namespace std;


void ReadMarks(int ArrMarks[3])
{
    cout << "Please Enter Your First Mark: ", cin >> ArrMarks[0];
    cout << "Please Enter Your Second Mark: ", cin >> ArrMarks[1];
    cout << "Please Enter Your Third Mark: ", cin >> ArrMarks[2];
}

int SumOfMarks(int ArrMarks[3])
{
    return ArrMarks[0] + ArrMarks[1] + ArrMarks[2];
}

float AvgOfMarks(int ArrMarks[3])
{
    return (float)SumOfMarks(ArrMarks) / 3;
}

void PrintAvg(float Avg)
{
    cout << "\n The Average Of The Entered Marks is: " << Avg << "\n";
}



int main()
{
    int ArrMarks[3];

    ReadMarks(ArrMarks);

    PrintAvg(AvgOfMarks(ArrMarks));


    return 0;
}
