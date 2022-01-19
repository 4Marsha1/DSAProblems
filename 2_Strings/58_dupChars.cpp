#include <bits/stdc++.h>
using namespace std;

// Hashing
int main()
{
    string s = "test string";
    unordered_map<char, int> map;
    for (int i = 0; i < s.length(); i++)
        map[s[i]]++;
    for (int i = 0; i < s.length(); i++)
    {
        if (map[s[i]] > 1)
        {
            cout << s[i] << " " << map[s[i]] << endl;
            map[s[i]] = 0;
        }
    }
}