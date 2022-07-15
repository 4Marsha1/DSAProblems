#include <bits/stdc++.h>
using namespace std;

bool cycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (cycle(it, adj, vis, dfsVis))
                return true;
        }
        else if (dfsVis[it])
            return true;
    }
    dfsVis[node] = 0;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<int> vis(V, 0);
    vector<int> dfsVis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (cycle(i, adj, vis, dfsVis))
                return true;
        }
    }
    return false;
}