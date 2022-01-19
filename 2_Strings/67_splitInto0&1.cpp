#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int cnt0 = 0, cnt1 = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
        if (cnt1 == cnt0)
            cnt++;
    }
    if (cnt0 != cnt1)
    {
        cout << -1;
        return 0;
    }
    cout << cnt;
}