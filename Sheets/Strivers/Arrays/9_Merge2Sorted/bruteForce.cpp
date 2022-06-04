#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int array[n + m];
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                array[k] = nums1[i];
                i++;
                k++;
            }
            else
            {
                array[k] = nums2[j];
                j++;
                k++;
            }
        }
        while (i < m)
        {
            array[k] = nums1[i];
            i++;
            k++;
        }
        while (j < n)
        {
            array[k] = nums2[j];
            j++;
            k++;
        }
        for (int i = 0; i < n + m; i++)
        {
            nums1[i] = array[i];
        }
    }
};