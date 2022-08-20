bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            queue<pair<int, int>> q;
            q.push({i, -1});
            vis[i] = 1;
            while (!q.empty())
            {
                int curr = q.front().first;
                int prev = q.front().second;
                q.pop();
                for (auto it : adj[curr])
                {
                    if (!vis[it])
                    {
                        q.push({it, curr});
                        vis[it] = 1;
                    }
                    else if (prev != it)
                        return true;
                }
            }
        }
    }
    return false;
}