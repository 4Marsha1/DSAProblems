#include <bits/stdc++.h>
using namespace std;

// Brute Force ----------> O(n2)
// Modified NGL
vector<int> stockSpan(int a[], int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] <= a[i])
                cnt++;
            else
                break;
        }
        ans.push_back(cnt);
    }
    return ans;
}

// Using stack -------> O(n)
// stack<pair<int,int>> ------> <value, index>
vector<int> stockSpan(int a[], int n)
{
    vector<int> ans;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first < a[i])
            st.pop();
        if (st.empty())
            ans.push_back(1);
        else
            ans.push_back(i - st.top().second);
        st.push({a[i], i});
    }
    return ans;
}

// LeetCode ---------> Great way to look
class StockSpanner
{
private:
    stack<pair<int, int>> st;
    int index;

public:
    StockSpanner()
    {
        index = -1;
    }

    int next(int price)
    {
        index++;
        while (!st.empty() && st.top().first <= price)
            st.pop();
        int res;
        if (st.empty())
            res = index + 1;
        else
            res = index - st.top().second;
        st.push({price, index});
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ans = stockSpan(a, n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}