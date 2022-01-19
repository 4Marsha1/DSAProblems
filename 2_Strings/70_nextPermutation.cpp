#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(int n, vector<int> nums)
{
    // code here
    int k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(nums.begin(), nums.end());
        return nums;
    }
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                break;
            }
        }
        int t = nums[l];
        nums[l] = nums[k];
        nums[k] = t;
        reverse(nums.begin() + k + 1, nums.end());
        return nums;
    }
}