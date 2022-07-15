#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &a, int idx, int n)
{
    if (idx >= n / 2)
        return;
    swap(a[idx], a[n - idx - 1]);
    reverse(a, idx + 1, n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    reverse(a, 0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}