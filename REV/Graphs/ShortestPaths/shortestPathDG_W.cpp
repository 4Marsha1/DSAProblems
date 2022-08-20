#include <bits/stdc++.h>
using namespace std;

void topo(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
            topo(it.first, adj, vis, st);
    }
    st.push(node);
    return;
}

void shortestPath(int V, vector<pair<int, int>> adj[], vector<int> &ans)
{
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
        if (!vis[i])
            topo(i, adj, vis, st);
    ans[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        int currDistance = ans[node];
        if (ans[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if (currDistance + it.second < ans[it.first])
                {
                    ans[it.first] = currDistance + it.second;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<int> ans(n, INT_MAX);
    shortestPath(n, adj, ans);
    for (auto it : ans)
        cout << it << " ";
}