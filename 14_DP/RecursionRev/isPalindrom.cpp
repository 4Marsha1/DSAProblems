#include <bits/stdc++.h>
using namespace std;

bool isPal(string s, int idx, int n)
{
    if (idx >= n / 2)
        return true;
    if (s[idx] == s[n - idx - 1] && isPal(s, idx + 1, n))
        return true;
    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << isPal(s, 0, s.length());
}