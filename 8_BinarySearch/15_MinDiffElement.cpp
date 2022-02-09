#include <bits/stdc++.h>
using namespace std;

// at the end of the loop, if element not found
// High and Low are adjacent elements but High < Low
int minDiff(int a[], int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == k)
            return a[mid];
        else if (a[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (abs(k - a[low]) < abs(k - a[high]))
        return a[low];
    else
        return a[high];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << minDiff(a, n, k);
}