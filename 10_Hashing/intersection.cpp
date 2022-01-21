#include <bits/stdc++.h>
using namespace std;

int intersectionArrays(int a[], int n, int b[], int m)
{
    unordered_set<int> set;
    for (int i = 0; i < n; i++)
        set.insert(a[i]);
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (set.find(b[i]) != set.end())
        {
            cnt++;
            set.erase(b[i]);
        }
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
    cout << intersectionArrays(a, n, b, m);
}