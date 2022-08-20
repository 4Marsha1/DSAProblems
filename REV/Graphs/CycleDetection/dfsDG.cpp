bool check(int node, vector<int> &vis, vector<int> &dfsVis, vector<int> adj[])
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (check(it, vis, dfsVis, adj))
                return true;
        }
        else if (dfsVis[it])
            return true;
    }
    dfsVis[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> dfsVis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (check(i, vis, dfsVis, adj))
                return true;
        }
    }
    return false;
}