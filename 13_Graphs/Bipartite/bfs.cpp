#include <bits/stdc++.h>
using namespace std;

bool check(int node, vector<int> &color, vector<vector<int>> &graph)
{
    queue<int> q;
    color[node] = 1;
    q.push(node);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        for (auto it : graph[n])
        {
            if (color[it] == -1)
            {
                q.push(it);
                color[it] = 1 - color[n];
            }
            else if (color[it] == color[n])
                return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int nodes = graph.size();
    vector<int> color(nodes, -1);
    for (int i = 0; i < nodes; ++i)
    {
        if (color[i] == -1)
        {
            if (!check(i, color, graph))
                return false;
        }
    }
    return true;
}