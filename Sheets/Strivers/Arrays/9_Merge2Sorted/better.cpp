#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int j = 0;
        while (j < n)
        {
            if (nums1[m - 1] > nums2[j])
            {
                swap(nums2[j], nums1[m - 1]);
                sort(nums1.begin(), nums1.begin());
                sort(nums2.begin(), nums2.end());
            }
            else
            {
                j++;
            }
        }
    }
};