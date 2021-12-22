#include <bits/stdc++.h>
using namespace std;

// Kadane's algorithm
int main()
{
    // input
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // initilaise 2 variables to store maximum Sum and current Sum
    int maxSum = INT_MIN, currSum = 0;
    for (int i = 0; i < n; i++)
    {
        // Current Sum (0 till ith)
        currSum += arr[i];
        // if current sum gets negative, make it 0
        if (currSum < 0)
            currSum = 0;
        // maxSum to be max of maxSum and current Sum
        maxSum = max(maxSum, currSum);
    }
    cout << maxSum;
}