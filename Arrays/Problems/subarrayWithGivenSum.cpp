// Given an unsorted array A of size N of non-negative integers, find a continuous
// subarray which adds to a given number S.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int i = 0, j = 1, sum = a[0] + a[1];
    while (j < n)
    {
        if (sum == s)
        {
            cout << i << " " << j;
            return 0;
        }
        else if (sum < s)
        {
            j++;
            sum += a[j];
        }
        else
        {
            sum -= a[i];
            i++;
        }
    }
}