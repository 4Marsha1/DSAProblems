#include <bits/stdc++.h>
using namespace std;

// Recursive ---------> Pick and Dont Pick method
void subsequence(string s, string output, vector<string> &ans)
{
    if (s.empty())
    {
        ans.push_back(output);
        return;
    }
    subsequence(s.substr(1), output + s[0], ans);
    subsequence(s.substr(1), output, ans);
}

int main()
{
    string s = "abc";
    string output = "";
    vector<string> ans;
    subsequence(s, output, ans);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}