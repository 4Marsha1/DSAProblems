#include <bits/stdc++.h>
using namespace std;

int unionArrays(int a[], int n, int b[], int m)
{
    unordered_set<int> set;
    for (int i = 0; i < n; i++)
        set.insert(a[i]);
    for (int i = 0; i < m; i++)
        set.insert(b[i]);
    return set.size();
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
    cout << unionArrays(a, n, b, m);
}