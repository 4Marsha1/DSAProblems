#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProf = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProf = max(maxProf, prices[i] - minPrice);
    }
    return maxProf;
}