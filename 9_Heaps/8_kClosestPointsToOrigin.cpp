#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> ppi;
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<ppi> maxHeap;
    for (int i = 0; i < points.size(); i++)
    {
        maxHeap.push({(points[i][0] * points[i][0]) + (points[i][1] * points[i][1]), {points[i][0], points[i][1]}});
        if (maxHeap.size() > k)
            maxHeap.pop();
    }
    vector<vector<int>> ans;
    while (!maxHeap.empty())
    {
        pair<int, int> p = maxHeap.top().second;
        ans.push_back({p.first, p.second});
        maxHeap.pop();
    }
    return ans;
}