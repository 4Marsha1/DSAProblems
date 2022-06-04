#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    int n = A.size() + 1;

    vector<int> substitute(n, 0);

    vector<int> ans;

    for (int i = 0; i < A.size(); i++)
    {
        substitute[A[i]]++;
    }

    for (int i = 1; i <= A.size(); i++)
    {
        if (substitute[i] == 0 || substitute[i] > 1)
        {
            ans.push_back(i);
        }
    }

    return ans;
}
