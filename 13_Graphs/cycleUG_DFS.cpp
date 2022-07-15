#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int node, int pre, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it, node, adj, vis))
                return true;
        }
        else if (pre != it)
            return true;
    }
    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}