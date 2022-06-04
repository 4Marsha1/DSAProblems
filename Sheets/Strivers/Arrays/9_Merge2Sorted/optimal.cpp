// GAP METHOD
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int gap = ceil(float((n + m) / 2));
        while (gap > 0)
        {
            int i = 0, j = gap;
            while (j < n + m)
            {
                if (j < m && nums1[i] > nums2[j])
                    swap(nums1[i], nums2[j]);
                else if (i < m && j >= m && nums1[i] > nums2[j - m])
                    swap(nums1[i], nums2[j - m]);
                else if (i >= m && j >= m && nums1[i - m] > nums2[j - m])
                    swap(nums1[i - m], nums2[j - m]);
                i++;
                j++;
            }
            if (gap == 1)
                gap = 0;
            else
                gap = ceil(float(gap / 2));
        }
        for (int i = 0; i < n; i++)
            nums1[i + m] = nums2[i];
    }
};