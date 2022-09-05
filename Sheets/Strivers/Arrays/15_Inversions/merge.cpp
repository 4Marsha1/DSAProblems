#include <bits/stdc++.h>

long long merge(long long *a, long long *temp, int left, int mid, int right)
{
    int cnt = 0;
    int i = left, j = mid, k = left;
    while (i <= mid - 1 && j <= right)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            cnt = cnt + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = a[i++];
    while (j <= right)
        temp[k++] = a[j++];
    for (int i = left; i <= right; i++)
        a[i] = temp[i];
    return cnt;
}
long long _merge(long long *a, long long *temp, int left, int right)
{
    long long cnt = 0;
    while (left < right)
    {
        int mid = (left + right) / 2;
        cnt += _merge(a, temp, left, mid);
        cnt += _merge(a, temp, mid + 1, right);
        cnt += merge(a, temp, left, mid + 1, right);
    }
    return cnt;
}
long long getInversions(long long *a, int n)
{
    long long temp[n];
    return _merge(a, temp, 0, n - 1);
}