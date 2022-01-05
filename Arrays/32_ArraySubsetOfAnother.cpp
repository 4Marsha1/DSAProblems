#include <bits/stdc++.h>
using namespace std;

// Hashing
string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_set<int> hashSet;
    for (int i = 0; i < n; i++)
        hashSet.insert(a1[i]);

    string ans = "Yes";
    for (int i = 0; i < m; i++)
    {
        if (!(hashSet.find(a2[i]) != hashSet.end()))
        {
            ans = "No";
            break;
        }
    }
    return ans;
}