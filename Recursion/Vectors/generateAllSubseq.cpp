#include <bits/stdc++.h>
using namespace std;

void getSubseq(string s, string output, vector<string> &ans)
{
    if (s.length() == 0)
    {
        ans.push_back(output);
        return;
    }
    getSubseq(s.substr(1), output + s[0], ans);
    getSubseq(s.substr(1), output, ans);
}

int main()
{
    string s = "abc", output = "";
    vector<string> ans;
    getSubseq(s, output, ans);
    for (string str : ans)
    {
        cout << str << " ";
    }
}