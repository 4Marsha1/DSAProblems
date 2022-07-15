#include <bits/stdc++.h>
using namespace std;

int subsEqualK(int a[], int idx, int n, int k, int sum)
{
    if (idx == n)
    {
        if (sum == k)
            return 1;
        return 0;
    }
    return subsEqualK(a, idx + 1, n, k, sum + a[idx]) + subsEqualK(a, idx + 1, n, k, sum);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[] = {5, 12, 3, 17, 1, 18, 15, 3, 17};

    cout << subsEqualK(a, 0, n, k, 0);
}