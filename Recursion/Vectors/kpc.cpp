#include <bits/stdc++.h>
using namespace std;

string codes[] = {":;", "abc", "def", "ghi", "jkl",
                  "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKPC(string s)
{
    if (s.length() == 0)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    vector<string> rest = getKPC(s.substr(1));
    vector<string> ans;
    string code = codes[s[0] - '0'];
    for (int i = 0; i < code.length(); i++)
    {
        for (string str : rest)
        {
            ans.push_back(code[i] + str);
        }
    }
    return ans;
}

int main()
{
    string s = "78";
    vector<string> ans;
    ans = getKPC(s);
    for (string str : ans)
    {
        cout << str << " ";
    }
}