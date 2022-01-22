#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &a)
{
    vector<int> ans;
    stack<int> st;
    int n = a.size();
    for (int i = n - 2; i >= 0; i--)
        st.push(a[i]);
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