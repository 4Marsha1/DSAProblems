#include <bits/stdc++.h>
using namespace std;

// O(n) Time Complexity
int linearSearch(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
            return i;
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << linearSearch(a, n, k);
}