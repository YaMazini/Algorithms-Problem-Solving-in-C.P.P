

#include <iostream>
using namespace std;

struct stTaskDuration 
{
    float Days;
    float Hours;
    float Minutes;
    float Seconds;
};


float ReadPositiveNumber(string Message)
{
    float Number = 0;

    do
    {
        cout << Message, cin >> Number;

    } while (Number <= 0);

    return Number;
}

stTaskDuration ReadDuration()
{
    stTaskDuration Duration;

    Duration.Days = ReadPositiveNumber("Please Enter The Number of Days: ");
    Duration.Hours = ReadPositiveNumber("Please Enter The Number of Hours: ");
    Duration.Minutes = ReadPositiveNumber("Please Enter The Number of Minutes: ");
    Duration.Seconds = ReadPositiveNumber("Please Enter The Number of Seconds: ");

    cout << "\n";

    return Duration;
}


double CalculateDurationInSeconds(stTaskDuration Duration)
{
    return (Duration.Days * 24 * 60 * 60) + (Duration.Hours * 60 * 60) + (Duration.Minutes * 60) + Duration.Seconds;
}



int main()
{
    double DurationInSeconds = CalculateDurationInSeconds(ReadDuration());

    cout << " Task Duration In Seconds: " << DurationInSeconds << "s\n";


    return 0;
}