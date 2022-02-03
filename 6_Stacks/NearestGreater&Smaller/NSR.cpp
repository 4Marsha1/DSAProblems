#include <bits/stdc++.h>
using namespace std;

// brute force ------> O(n2)
vector<int> NSR(int a[], int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
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
vector<int> NSR(int a[], int n)
{
    vector<int> ans;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= a[i])
            st.pop();
        ans.push_back(st.empty() ? -1 : st.top());
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
    vector<int> ans = NSR(a, n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}