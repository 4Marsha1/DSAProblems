#include <bits/stdc++.h>
using namespace std;

int countSS(int a[], int ind, int sum, int target, int n)
{
    // base case
    if (ind == n)
    {
        if (sum == target)
            return 1;
        return 0;
    }
    // Dont Pick
    int leftCall = countSS(a, ind + 1, sum, target, n);

    // Pick
    sum += a[ind];
    int rightCall = countSS(a, ind + 1, sum, target, n);
    sum -= a[ind];

    return leftCall + rightCall;
}

int main()
{
    int n, target;
    cin >> n >> target;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << countSS(a, 0, 0, target, n);
}