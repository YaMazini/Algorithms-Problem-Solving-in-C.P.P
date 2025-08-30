
#include <iostream>
#include <string>
using namespace std;

string ReadPassword(string Message)
{
    string Password;
    do
    {
        cout << Message, cin >> Password;
    
    } while (Password.length() != 3);
    
    return Password;
}

void CrackPassword(string UserPassword)
{
    int Trial = 0;
    cout << "\n";

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                Trial++;

                string GeneratedPassword = "";
                GeneratedPassword += char(i);
                GeneratedPassword += char(j);
                GeneratedPassword += char(k);


                cout << "Trial [" << Trial << "]:" << GeneratedPassword << "\n";

                if (GeneratedPassword == UserPassword)
                {
                    cout << "\n Password is: " << UserPassword << "\n";
                    cout << " Found after " << Trial << " Trial(s)\n";

                    return;
                }
            }
        }
    }
}


int main()
{
    string UserPassword = ReadPassword("Please guess a 3-Letter password: ");

    CrackPassword(UserPassword);


    return 0;
}