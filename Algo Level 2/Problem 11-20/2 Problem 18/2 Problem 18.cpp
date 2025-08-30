#include <iostream>
#include <string>
using namespace std;

string ReadText(string Message)
{
    string Text;
    cout << Message, cin >> Text;

    return Text;
}

string EncryptText(string Text, short EncryptionValue)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionValue);
    }

    return Text;
}

string DecryptText(string Text, short EncryptionValue)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionValue);
    }

    return Text;
}



int main()
{
    const short EncryptionValue = 2;
    string TextAfterEncryption, TextAfterDecryption;
    string Text = ReadText("Please enter a text: ");

    TextAfterEncryption = EncryptText(Text, EncryptionValue);
    TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptionValue);


    cout << "\n Text Before Encryption: " << Text << "\n";
    cout << " Text After Encryption: " << TextAfterEncryption << "\n";
    cout << " Text After Decryption: " << TextAfterDecryption << "\n";

    
    return 0;
}