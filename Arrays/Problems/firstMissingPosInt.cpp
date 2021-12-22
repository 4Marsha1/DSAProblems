// Find the smallest positive missing number in the given array.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool check[N];
    for (int i = 0; i < N; i++)
        check[i] = false;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            check[a[i]] = true;
    }

    for (int i = 0; i < N; i++)
        if (check[i] == false)
        {
            cout << i;
            return 0;
        }
}