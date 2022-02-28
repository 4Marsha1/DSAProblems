
// https://leetcode.com/problems/contiguous-array/

#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    int maxLen = 0, sum = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] == 0)
            nums[i] = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == 0)
            maxLen = i + 1;
        else
        {
            if (map.find(sum) != map.end())
                maxLen = max(maxLen, i - map[sum]);
            else
                map[sum] = i;
        }
    }
    return maxLen;
}