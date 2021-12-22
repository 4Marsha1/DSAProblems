// An arithmetic array is an array that contains at least two integers and the differences between consecutive integers are equal.
// For example, [ 9, 10 ], [ 3, 3, 3 ], and[ 9, 7, 5, 3 ] are arithmetic arrays,
// while[1, 3, 3, 7], [ 2, 1, 2 ], and[ 1, 2, 4 ] are not arithmetic arrays.

// She wants to choose a contiguous arithmetic subarray from her array that has the maximum length.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // Applying Kadane's Algorithm
    int maxlength = 2, currLength = 2;
    for (int i = 1; i < n - 1; i++)
    {
        if (abs(arr[i] - arr[i - 1]) == abs(arr[i + 1] - arr[i]))
        {
            currLength++;
            maxlength = max(maxlength, currLength);
        }
        else
            currLength = 2;
    }

    cout << maxlength;
}