#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{

    long long maxSum = INT_MIN, curSum = 0;
    for (int i = 0; i < n; i++)
    {
        curSum += arr[i];
        if (curSum > maxSum)
            maxSum = curSum;
        if (curSum < 0)
            curSum = 0;
    }
    return maxSum;
}