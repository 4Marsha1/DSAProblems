#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int ind1 = -1, ind2 = -1;
        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i + 1] > nums[i])
            {
                ind1 = i;
                break;
            }
        }
        if (ind1 == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > ind1; --i)
        {
            if (nums[i] > nums[ind1])
            {
                ind2 = i;
                break;
            }
        }
        swap(nums[ind1], nums[ind2]);
        reverse(nums.begin() + ind1 + 1, nums.end());
    }
};