#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            int start = intervals[i][0], end = intervals[i][1];
            if (!ans.empty())
            {
                if (start <= ans[ans.size() - 1][1])
                    continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (end >= intervals[j][0])
                {
                    end = max(end, intervals[j][1]);
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};