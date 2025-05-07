#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<pair<int, int>>> &adj, int n, int src)
{
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int wt = adj[u][i].second;
            if (dist[v] > w + wt)
            {
                dist[v] = w + wt;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        cout << dist[i] << endl;
    }
}
int main()
{

    int n, m;
    cout << "enter no. of nodes" << endl;
    cin >> n;
    cout << "enter no. of edges" << endl;
    cin >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << "enter sourc node" << endl;
    int src;
    cin >> src;
    solve(adj, n, src);
    return 0;
}