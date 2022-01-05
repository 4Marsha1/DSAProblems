#include <bits/stdc++.h>
using namespace std;

// brute Force -----------> O(n3)
int maxSumSubarray(int arr[], int n)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k < j; k++)
                sum += arr[k];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// Kadane's Algo --------------> O(n)
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

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSumSubarray(arr, n);
}