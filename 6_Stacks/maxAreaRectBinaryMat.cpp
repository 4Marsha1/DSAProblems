#include <bits/stdc++.h>
using namespace std;

int MAH(vector<int> a);

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int> ans(m, 0);
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '0')
                ans[j] = 0;
            else
                ans[j] += matrix[i][j] - '0';
        }
        int area = MAH(ans);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int MAH(vector<int> a)
{
    int n = a.size();
    // NSL
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

    // NSR
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

    // Width = Right - left - 1
    vector<int> width(n);
    for (int i = 0; i < n; i++)
        width[i] = right[i] - left[i] - 1;
    int maxA = INT_MIN;
    // Area = width*height ---> width*a
    for (int i = 0; i < n; i++)
    {
        width[i] *= a[i];
        maxA = max(maxA, width[i]);
    }
    return maxA;
}