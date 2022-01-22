#include <bits/stdc++.h>
using namespace std;

int maxAreaHisto(int a[], int n)
{
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

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << maxAreaHisto(a, n);
}