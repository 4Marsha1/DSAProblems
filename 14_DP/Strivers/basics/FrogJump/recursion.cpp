#include <bits/stdc++.h>
using namespace std;
int frog(int en[], int n)
{
    if (n == 0)
        return 0;
    int right = INT_MAX;
    int left = frog(en, n - 1) + abs(en[n] - en[n - 1]);
    if (n > 1)
        right = frog(en, n - 2) + abs(en[n] - en[n - 2]);
    return min(left, right);
}
int main()
{
    int n;
    cin >> n;
    int en[n];
    for (int i = 0; i < n; i++)
        cin >> en[i];
    cout << frog(en, n - 1);
}