#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "AACD";
    string t = "ACDA";
    if (s.length() != t.length())
    {
        cout << "False";
        return 0;
    }

    // Double the first string and check
    // if second string is a substring of the doubled first string
    string temp = s + s;

    // string::npos -------------> highest possible value
    if (temp.find(t) != string::npos)
        cout << "True";
    else
        cout << "False";
}