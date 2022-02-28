
// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &a)
{
    int n = a.size();
    vector<int> left;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first >= a[i])
            st.pop();
        if (st.empty())
            left.push_back(-1);
        else
            left.push_back(st.top().second);
        st.push({a[i], i});
    }
    vector<int> right;
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first >= a[i])
            st.pop();
        if (st.empty())
            right.push_back(n);
        else
            right.push_back(st.top().second);
        st.push({a[i], i});
    }
    reverse(right.begin(), right.end());
    int maxA = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, (right[i] - left[i] - 1) * a[i]);
    }
    return maxA;
}