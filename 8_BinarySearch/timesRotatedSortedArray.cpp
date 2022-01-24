#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &a)
{
    int n = a.size();
    int start = 0, end = n - 1;
    if (a[0] < a[n - 1])
        return a[0];
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        int prev = (mid + n - 1) % n, next = (mid + 1) % n;
        if (a[mid] <= a[prev] && a[mid] <= a[next])
            return a[mid];
        if (a[start] <= a[mid])
            start = mid + 1;
        if (a[mid] <= a[end])
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << findMin(a);
}