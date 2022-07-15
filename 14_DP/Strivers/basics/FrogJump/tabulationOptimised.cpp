#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int en[n];
    for (int i = 0; i < n; i++)
        cin >> en[i];
    vector<int> dp(n);
    int left, right = INT_MAX;
    int prev = 0;
    int prev2;
    for (int i = 1; i < n; i++)
    {
        left = prev + abs(en[i] - en[i - 1]);
        if (i > 1)
            right = prev2 + abs(en[i] - en[i - 2]);
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    cout << prev;
}