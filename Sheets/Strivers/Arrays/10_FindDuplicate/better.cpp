#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int freq[n];
        for (int i = 0; i < n; i++)
            freq[i] = 0;
        for (int i = 0; i < n; i++)
        {
            freq[nums[i] - 1]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (freq[i] > 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
};