#include <bits/stdc++.h>
using namespace std;

// Hashing
int intersection(int a[], int n, int b[], int m)
{
    unordered_map<int, int> map;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        map[a[i]] = i;
    }
    for (int i = 0; i < m; i++)
    {
        if (map.find(b[i]) != map.end())
            cnt++;
    }
    return cnt;
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
    cout << intersection(a, n, b, m);
}