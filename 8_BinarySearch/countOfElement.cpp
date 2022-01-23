#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(int a[], int n, int k);
int lastOccurrence(int a[], int n, int k);

int count(int a[], int n, int k)
{
    int firstIdx = firstOccurrence(a, n, k);
    int lastIdx = lastOccurrence(a, n, k);
    return (lastIdx - firstIdx + 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << count(a, n, k);
}

int firstOccurrence(int a[], int n, int k)
{
    int start = 0, end = n - 1, ans = -1;
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (a[mid] == k)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (a[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}

int lastOccurrence(int a[], int n, int k)
{
    int start = 0, end = n - 1, ans = -1;
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (a[mid] == k)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (a[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}