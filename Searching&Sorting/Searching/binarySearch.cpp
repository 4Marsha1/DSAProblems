#include <bits/stdc++.h>
using namespace std;

// O(logn) Time Complexity
int binarySearch(int a[], int n, int k)
{
    // array must be sorted always
    sort(a, a + n);
    // 2 pointer -> BEGIN & END
    int low = 0, high = n - 1;
    // While element exists
    while (low <= high)
    {
        // MID POINT
        int mid = (low + high) / 2;
        // If mid element is target, return index
        if (a[mid] == k)
            return mid;
        // if mid element is greater than target,
        // then target exists in LEFT half
        else if (a[mid] > k)
            high = mid - 1;
        // if mid element is less than target,
        // then target exists in RIGHT half
        else
            low = mid + 1;
    }
    // Target NOT FOUND
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