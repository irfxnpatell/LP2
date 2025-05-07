#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int start, int n)
{
    queue<int> q;
    vector<int> vis(n + 1, 0);
    q.push(start);
    vis[start] = 1;
    while (!q.empty())

    {
        int front = q.front();
        q.pop();
        cout << front << " ";
        for (int i = 0; i < adj[front].size(); i++)
        {
            if (!vis[adj[front][i]])
            {
                q.push(adj[front][i]);
                vis[adj[front][i]] = 1;
            }
        }
    }
}
void dfs(vector<int> adj[], int vis[], int start)
{
    cout << start << " ";
    vis[start] = 1;
    for (int i = 0; i < adj[start].size(); i++)
    {
        if (!vis[adj[start][i]])
        {
            dfs(adj, vis, adj[start][i]);
        }
    }
}
void dfs2(vector<int> adj[], int start, int n) // iterative
{
    stack<int> st;
    vector<int> vis(n + 1, 0);
    st.push(start);
    vis[start] = 1;
    while (!st.empty())

    {
        int top = st.top();
        st.pop();
        cout << top << " ";
        for (int i = 0; i < adj[top].size(); i++)
        {
            if (!vis[adj[top][i]])
            {
                st.push(adj[top][i]);
                vis[adj[top][i]] = 1;
            }
        }
    }
}
void dls(vector<int> adj[], int node, int limit, int vis[])
{
    if (limit < 0)
        return;

    cout << node << " ";
    vis[node] = 1;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int next = adj[node][i];
        if (!vis[next])
        {
            dls(adj, next, limit - 1, vis);
        }
    }
}
int main()
{

    int n, m;
    cout << "enter num of nodes" << endl;
    cin >> n;
    cout << "enter num of edges" << endl;
    cin >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    bfs(adj, 1, n);
    int vis[n + 1] = {0};
    cout << endl;
    dfs(adj, vis, 1);
    cout << endl;
    dfs2(adj, 1, n);
    cout << endl;
    int vis2[n + 1] = {0};
    cout << "enter depth limit" << endl;
    int limit;
    cin >> limit;
    cout << "depth limited search" << endl;
    dls(adj, 1, limit, vis2);

    return 0;
}
// 2 1 1 3 3 4 2 4 2 5 4 5