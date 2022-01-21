#include <bits/stdc++.h>
using namespace std;

int cntDistinct(int a[], int n)
{
    unordered_set<int> set;
    for (int i = 0; i < n; i++)
        set.insert(a[i]);
    return set.size();
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << cntDistinct(a, n);
}