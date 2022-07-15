#include <bits/stdc++.h>
using namespace std;

void subs(string s, string res, vector<string> &ans)
{
    if (s.length() == 0)
    {
        ans.push_back(res);
        return;
    }
    subs(s.substr(1), res + s[0], ans);
    subs(s.substr(1), res, ans);
}

int main()
{
    string s;
    vector<string> ans;
    cin >> s;
    subs(s, "", ans);
    for (auto it : ans)
    {
        cout << it << endl;
    }
}