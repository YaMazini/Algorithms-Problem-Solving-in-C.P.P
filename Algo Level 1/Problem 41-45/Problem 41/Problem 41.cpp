
#include <iostream>
#include <cmath>
using namespace std;


float ReadPositiveNumber(string Message)
{
    float NumberOfHours = 0;

    do
    {
        cout << Message, cin >> NumberOfHours;

    } while (NumberOfHours <= 0);    //while the number of hours negative recent the message!
    cout << " \n";

    return NumberOfHours;
}


float CalculateNumberOfDays(float NumberOfHours)
{
    return round(NumberOfHours / 24);
}

float CalculateNumberofWeeks(float NumberOfHours)
{
    return round(NumberOfHours / 168);        //Hours in a week: 168 = 24 Hours * 7 Days
}



int main()
{
    float NumberOfHours = ReadPositiveNumber("Please Enter the Number of Hours: ");

    float NumberOfDays = CalculateNumberOfDays(NumberOfHours);
    float NumberOfWeeks = CalculateNumberofWeeks(NumberOfHours);

    cout << NumberOfHours << " Hours\n";
    cout << NumberOfDays << " Days\n";
    cout << NumberOfWeeks << " Weeks\n";


    return 0;
}

