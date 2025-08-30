#include <iostream>
using namespace std;


string ReadString(const string Message)
{
    string S1;
    cout << Message << endl;
    cin >> S1;
    cout << "\n";

    return S1;
}

char ReadChar(const string Message)
{
    char C1;
    cout << Message << endl;
    cin >> C1;

    while (cin.fail())
    {
        
    }

    cout << "\n";

    return C1;
}

char InvertingLetter(const char Letter)
{
    return (isupper(Letter)) ? tolower(Letter) : toupper(Letter);
}

short CharCounterInString(const char Letter, string S1, bool MatchCase = true)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == Letter)
                Counter++;
        }
        
        else if (!MatchCase)
        {
            if (tolower(S1[i]) == tolower(Letter))
                Counter++;
        }
    }
    

    return Counter;
}


int main()
{
    string S1 = ReadString("Please enter your string: ");
    char Letter = ReadChar("Please enter a char to count: ");
    char InvertedLetter = InvertingLetter(Letter);

    printf("Letter \'%c\' Count: ", Letter);
    cout << CharCounterInString(Letter, S1) << "\n";

    printf("Letter \'%c\' Or \'%c\' Count: ", Letter, InvertedLetter);
    cout << CharCounterInString(Letter, S1, false) << "\n";


    return 0;
}