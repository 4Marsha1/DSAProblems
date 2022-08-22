#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int ranK[100000];

void makeSet(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        ranK[i] = 0;
    }
}

int findPar(int node)
{
    if (node == parent[node])
        return node;
    return parent[node] = findPar(parent[node]);
}

void unioN(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (ranK[u] < ranK[v])
    {
        parent[u] = v;
    }
    else if (ranK[v] < ranK[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        ranK[u]++;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    makeSet(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        unioN(u, v);
    }
    for (int i = 1; i <= n; i++)
        cout << i << " " << parent[i] << endl;
}