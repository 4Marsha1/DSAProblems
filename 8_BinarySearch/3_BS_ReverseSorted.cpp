#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int n, int k)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == k)
            return mid;
        // same but these 2 conditions get reversed
        else if (a[mid] < k)
            r = mid - 1;
        else
            l = mid + 1;
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
    cout << binarySearch(a, n, k);
}