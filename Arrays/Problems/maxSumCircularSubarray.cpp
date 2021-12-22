#include <bits/stdc++.h>
using namespace std;

// Kadane's Algo
int main()
{
    // input
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // same as maxSumSubarray
    // but for circular arrays, we do a trick
    //          1. iterate from 0 to 2n-2 (feels like making an array twice size and storing the elements twice)
    //          2. whenever we index, we use [i%n] instead of [i], so that we use 1st element instead of (n+1)th element (which dont exist)
    int maxSum = INT_MIN, currSum = 0;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        currSum += arr[i % n];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
            currSum = 0;
    }
    cout << maxSum;
}