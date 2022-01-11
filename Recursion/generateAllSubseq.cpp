#include <iostream>
#include <vector>
using namespace std;

void gss(string s, string out, vector<string> &ans)
{
    if (s.length() == 0)
    {
        ans.push_back(out);
        return;
    }
    gss(s.substr(1), out, ans);
    gss(s.substr(1), out + s[0], ans);
}

int main()
{
    string s;
    cin >> s;
    string out = "";
    vector<string> ans;
    gss(s, out, ans);
    int cnt = 0;

    cout << '[';
    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}