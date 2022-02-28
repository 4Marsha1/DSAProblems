
// https://leetcode.com/problems/range-sum-query-immutable/

#include <bits/stdc++.h>
using namespace std;

class NumArray
{
    vector<int> arr;

public:
    NumArray(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            arr.push_back(nums[i]);
            if (i > 0)
                arr[i] += arr[i - 1];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return arr[right];
        return arr[right] - arr[left - 1];
    }
};