#include <bits/stdc++.h>
using namespace std;
int frog(int en[], int n, int k, int mn)
{
    if (n == 0)
        return 0;
    for (int i = 1; i <= k; i++)
    {
        if (n >= i)
        {
            mn = min(mn, frog(en, n - i, k, mn) + abs(en[n] - en[n - i]));
        }
    }
    return mn;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int en[n];
    for (int i = 0; i < n; i++)
        cin >> en[i];
    int mn = INT_MAX;
    cout << frog(en, n - 1, k, mn);
}