
#include <iostream>
using namespace std;


enum enDaysOfWeek{ Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7};

int ReadPositiveNumberInRange(string Message, int From, int To)
{
    int Number;
    do
    {
        cout << Message, cin >> Number;
    
    } while (Number < From || Number > To);
    cout << "\n";

    return Number;
}

enDaysOfWeek GetDayOfWeek()
{
    return (enDaysOfWeek)ReadPositiveNumberInRange("Please Enter the Number of the Day in he Week(1 - 7): ", 1, 7);
}

string DayOfWeek(enDaysOfWeek DayOfWeek)
{

    switch (DayOfWeek)
    {

    case enDaysOfWeek::Sunday:
        return "Sunday";
       
    case enDaysOfWeek::Monday:
        return "Monday";

    case enDaysOfWeek::Tuesday:
        return "Thuesday";

    case enDaysOfWeek::Wednesday:
        return "Wednesday";

    case enDaysOfWeek::Thursday:
        return "Thursday";

    case enDaysOfWeek::Friday:
        return "Friday";

    case enDaysOfWeek::Saturday:
        return "Saturday"; 
    
    }
}



int main()
{
    cout << " Its " << DayOfWeek(GetDayOfWeek()) << "!\n";

    return 0;
}