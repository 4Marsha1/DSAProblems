bool check(int node, int prev, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (check(it, node, adj, vis))
                return true;
        }
        else if (prev != it)
            return true;
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
        if (!vis[i])
            if (check(i, -1, adj, vis))
                return true;
    return false;
}