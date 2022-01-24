#include <bits/stdc++.h>
using namespace std;

int BSnearlysorted(int a[], int n, int k)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (a[mid] == k)
            return mid;
        else if (mid - 1 >= start and a[mid - 1] == k)
            return mid - 1;
        else if (mid + 1 <= end and a[mid + 1] == k)
            return mid + 1;
        else if (a[mid] > k)
            end = mid - 2;
        else
            start = mid + 2;
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
    cout << BSnearlysorted(a, n, k);
}