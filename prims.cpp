#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<pair<int, int>>> &adj, int n)
{
    vector<int> vis(n, 0);
    vector<pair<int, int>> mst;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // weight node parent
    pq.push({0, 0, -1});
    int d = 0;
    while (!pq.empty())
    {
        tuple<int, int, int> top = pq.top();
        int w = get<0>(top);
        int u = get<1>(top);
        int parent = get<2>(top);
        pq.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;

        if (parent != -1)
        {
            mst.push_back({u, parent});
            d += w;
        }
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (!vis[v])
            {
                pq.push({w, v, u});
            }
        }
    }
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i].first << "-" << mst[i].second << endl;
    }
    cout << "cost" << d;
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
    solve(adj, n);

    return 0;
}