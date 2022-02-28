
// https://leetcode.com/problems/online-stock-span/

#include <bits/stdc++.h>
using namespace std;

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