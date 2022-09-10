class StockSpanner
{
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

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */