#include <bits/stdc++.h>
using namespace std;

string printSeq(string s, string arr[])
{
    int n = s.length();
    string output = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            output += '0';
        else
        {
            int pos = s[i] - 'A';
            output += arr[pos];
        }
    }
    return output;
}

int main()
{
    string arr[] = {"2", "22", "222",
                    "3", "33", "333",
                    "4", "44", "444",
                    "5", "55", "555",
                    "6", "66", "666",
                    "7", "77", "777", "7777",
                    "8", "88", "888",
                    "9", "99", "999", "9999"};
    string s;
    cin >> s;
    cout << printSeq(s, arr);
}