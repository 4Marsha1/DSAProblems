#include <bits/stdc++.h>
using namespace std;

// The idea is to store prefix sums (sum from 0 to i) in a hashSet
// If the sum already exits in the hashet ---> this means the previous sum is nullified in due course
// in that case or if sum == 0, this means subarray with sum 0 exists

// hashing
bool subArrayExists(int arr[], int n)
{
    // Your code here
    unordered_set<int> hashSet;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || hashSet.find(sum) != hashSet.end())
            return true;
        hashSet.insert(sum);
    }
    return false;
}