
// https://leetcode.com/problems/first-bad-version/

#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int version)
{
    // Checks for quality of version
    // given in question
}

// FIRST OCCURENCE ---> USING BINARY SEARCH
int firstBadVersion(int n)
{
    int start = 0, end = n - 1, ans, mid = 0;
    while (start <= end)
    {
        mid = (start + (end - start) / 2);
        if (isBadVersion(mid) == true)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}