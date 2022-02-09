#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int a[], int n, int k)
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (a[mid] == k)
        {
            // move the search to left half to find even smaller index
            first = mid;
            high = mid - 1;
        }
        else if (a[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return first;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << firstOccurence(a, n, k);
}