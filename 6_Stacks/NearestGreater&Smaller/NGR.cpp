#include <bits/stdc++.h>
using namespace std;

// brute force --------> O(n2)
vector<int> NGR(int a[], int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                ans.push_back(a[j]);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            ans.push_back(-1);
    }
    return ans;
}

// using stack --------> O(n)
// 1. Traverse from Right to left
// 2. Reverse the output
vector<int> NGR(int a[], int n)
{
    stack<int> st;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[i] >= st.top())
            st.pop();
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(a[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ans = NGR(a, n);
}