#include <bits/stdc++.h>
using namespace std;

bool check(int node, vector<int> &color, vector<vector<int>> &graph)
{
    if (color[node] == -1)
        color[node] = 1;
    for (auto it : graph[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!check(it, color, graph))
                return false;
        }
        else if (color[it] == color[node])
            return false;
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