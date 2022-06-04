#include <bits/stdc++.h>
long long getInversions(long long *arr, int n)
{
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    return cnt;
}