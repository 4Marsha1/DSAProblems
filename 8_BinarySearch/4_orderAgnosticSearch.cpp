#include <bits/stdc++.h>
using namespace std;

int ascendingBS(int a[], int n, int k);
int descendingBS(int a[], int n, int k);

int orderAgnosticSearch(int a[], int n, int k)
{
    if (n == 1)
    {
        if (a[0] == k)
            return 0;
        else
            return -1;
    }
    if (a[0] > a[1])
        return descendingBS(a, n, k);
    else
        return ascendingBS(a, n, k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << orderAgnosticSearch(a, n, k);
}

int ascendingBS(int a[], int n, int k)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == k)
            return mid;
        else if (a[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int descendingBS(int a[], int n, int k)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == k)
            return mid;
        else if (a[mid] < k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}