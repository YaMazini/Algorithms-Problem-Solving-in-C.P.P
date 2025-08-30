#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ReadString(string Message)
{
    string S1;
    cout << Message << endl;
    getline(cin, S1);

    return S1;
}

string RemovePunctFromString(string S1)
{
    string S2 = "";
    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }

    return S2;
}

int main()
{
    string S1 = ReadString("Please enter your string: ");
    
    cout << "\n Original String: \n" << S1 << endl;

    cout << "\n Punctuations Removed: \n";
    cout << RemovePunctFromString(S1) << endl;


    return 0;
}