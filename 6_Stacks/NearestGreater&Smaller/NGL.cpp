#include <bits/stdc++.h>
using namespace std;

// brute force -------> O(n2)
vector<int> NGL(int a[], int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i - 1; j >= 0; j--)
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
// 1. Traverse from Left to Right
// 2. No reversal of output required
vector<int> NGL(int a[], int n)
{
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[i] >= st.top())
            st.pop();
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(a[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ans = NGL(a, n);
}