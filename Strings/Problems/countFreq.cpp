#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input
    string s;
    cin >> s;

    // store the frequency of each character
    int count[26] = {0};
    for (int i = 0; i < s.length(); i++)
        count[s[i] - 'a']++;

    // find the character with max freq and the max freq value
    int maxE = count[0];
    char ch = 'a';
    for (int i = 1; i < 26; i++)
        if (count[i] > maxE)
        {
            maxE = count[i];
            ch = i + 'a';
        }
    cout << maxE << " " << ch;
}