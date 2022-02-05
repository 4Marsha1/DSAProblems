#include <bits/stdc++.h>
using namespace std;

void kpc(vector<string> &ans, string s, string output, string codes[])
{
    if (s.length() == 0)
    {
        if (output == "")
            return;
        ans.push_back(output);
        return;
    }
    string code = codes[s[0] - '1'];
    for (int i = 0; i < code.length(); i++)
    {
        kpc(ans, s.substr(1), output + code[i], codes);
    }
}
vector<string> letterCombinations(string digits)
{
    string codes[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs",
                      "tuv", "wxyz"};
    vector<string> ans;
    kpc(ans, digits, "", codes);
    return ans;
}