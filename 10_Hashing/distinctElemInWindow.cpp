#include <bits/stdc++.h>
using namespace std;

void distinctWindow(int a[], int n, int k)
{
    unordered_set<int> set;
    for (int i = 0; i + k <= n; i++)
    {
        for (int j = i; j < i + k; j++)
            set.insert(a[j]);
        cout << set.size() << endl;
        set.erase(a[i]);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    distinctWindow(a, n, k);
}