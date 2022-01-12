#include <bits/stdc++.h>
using namespace std;

vector<string> getPaths(int n)
{
    if (n == 0)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    else if (n < 0)
    {
        vector<string> ans;
        return ans;
    }
    vector<string> paths1 = getPaths(n - 1);
    vector<string> paths2 = getPaths(n - 2);
    vector<string> paths3 = getPaths(n - 3);
    vector<string> ans;
    for (string str : paths1)
    {
        ans.push_back("1" + str);
    }
    for (string str : paths2)
    {
        ans.push_back("2" + str);
    }
    for (string str : paths3)
    {
        ans.push_back("3" + str);
    }
    return ans;
}

int main()
{
    int n = 4;
    vector<string> ans;
    ans = getPaths(4);
    for (string str : ans)
    {
        cout << str << " ";
    }
}