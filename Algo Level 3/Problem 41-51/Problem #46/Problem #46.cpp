#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stClientData
{
    string AccountNumber;
    string PinCode;
    string FullName;
    string PhoneNumber;
    double AccountBalance;
};

vector <string> SplitString(string S1, string Delim = " #//# ")
{
    vector <string> vWords;
    string Word;
    short pos = 0;

    while ((pos = S1.find(Delim)) != string::npos)
    {
        Word = S1.substr(0, pos);
        S1.erase(0, pos + Delim.length());

        if (Word != "")
        {
            vWords.push_back(Word);
        }
    }

    if (S1 != "")
    {
        vWords.push_back(S1);
    }

    return vWords;
}

stClientData ConvertLineToRecord(string S1, string Delim = " #//# ")
{
    stClientData ClientData;
    vector <string> vClientData = SplitString(S1, Delim);

    ClientData.AccountNumber = vClientData[0];
    ClientData.PinCode = vClientData[1];
    ClientData.FullName = vClientData[2];
    ClientData.PhoneNumber = vClientData[3];
    ClientData.AccountBalance = stod(vClientData[4]);

    return ClientData;
}

void PrintClientData(stClientData& ClientData)
{
    cout << "Account Number  : " << ClientData.AccountNumber << endl;
    cout << "Pin Code        : " << ClientData.PinCode << endl;
    cout << "Name            : " << ClientData.FullName << endl;
    cout << "Phone           : " << ClientData.PhoneNumber << endl;
    cout << "Account Balance : " << ClientData.AccountBalance << endl;
}


int main()
{
    string StrRecord = "A150 #//# 1234 #//# Yahya Mazini #//# 06234925 #//# 5000.000000";
    stClientData ClientData = ConvertLineToRecord(StrRecord);

    cout << " Line Record is: \n" << StrRecord << endl;

    cout << "\n The following is the extracted client record: \n\n";
    PrintClientData(ClientData);


    return 0;
}