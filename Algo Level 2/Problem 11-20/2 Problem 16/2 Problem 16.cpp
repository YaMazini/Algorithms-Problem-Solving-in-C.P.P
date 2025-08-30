#include <iostream>
#include <string>
using namespace std;

void PrintAllWords()
{
    string word = "";

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word += char(i);
                word += char(j);
                word += char(k);

                cout << word << "\n";
                word = "";
            }
        }
    }
    
}


int main()
{
    
    PrintAllWords();

    return 0;
}