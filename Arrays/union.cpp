#include <bits/stdc++.h>
using namespace std;

// Brute Force
int doUnionBrute(int a[], int n, int b[], int m)
{
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else
        {
            ans.push_back(a[i]);
            ans.push_back(b[j]);
            i++;
            j++;
        }
    }
    while (i < n)
    {
        ans.push_back(a[i]);
        i++;
    }
    while (j < m)
    {
        ans.push_back(b[j]);
        j++;
    }
    sort(ans.begin(), ans.end());
    int cnt = 0;
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] == ans[i - 1])
            cnt++;
    }
    return ans.size() - cnt;
}

// Using Hashing
int doUnion(int a[], int n, int b[], int m)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[a[i]] = i;
    }
    for (int i = 0; i < m; i++)
    {
        if (map.find(b[i]) != map.end())
            continue;
        else
            map[b[i]] = i;
    }
    return map.size();
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    cout << doUnion(a, n, b, m);
}