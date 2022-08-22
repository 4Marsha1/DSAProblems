// Brute Force O(N2)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int key[n];
    int parent[n];
    bool mst[n];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    parent[0] = -1;
    key[0] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int mini = INT_MAX, u;
        for (int v = 0; v < n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                mini = key[v];
                u = v;
            }
        }
        mst[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;
            if (mst[v] == false && wt < key[v])
            {
                parent[v] = u;
                key[v] = wt;
            }
        }
    }
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << endl;
}

// Optimal --> PQ --> O(NlogN)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int key[n];
    int parent[n];
    bool mst[n];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    parent[0] = -1;
    key[0] = 0;
    pq.push({0, 0});

    for (int count = 0; count < n - 1; count++)
    {
        int u = pq.top().second;
        pq.pop();
        mst[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;
            if (mst[v] == false && wt < key[v])
            {
                parent[v] = u;
                pq.push({key[v], v});
                key[v] = wt;
            }
        }
    }
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << endl;
}