#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 3
int drow[] = {1, 0, 0, -1};
int dcol[] = {0, 1, -1, 0};

struct Node
{
    Node *parent;
    int mat[N][N];
    int g, h;
    int x, y;
};
Node *newnode(int mat[N][N], int g, int x, int y, int nx, int ny, Node *parent)
{
    Node *node = new Node;
    node->parent = parent;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            node->mat[i][j] = mat[i][j];
        }
    }

    swap(node->mat[x][y], node->mat[nx][ny]);
    node->g = g;
    node->x = nx;
    node->y = ny;
    return node;
}

int heuristic(int start[N][N], int goal[N][N])
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (start[i][j] != 0 && (start[i][j] != goal[i][j]))
            {
                cnt++;
            }
        }
    }
    return cnt;
}

bool isSafe(int x, int y)
{
    if (x >= 0 && y >= 0 && x < N && y < N)
    {
        return true;
    }
    return false;
}

struct comp
{
    bool operator()(const Node *lhs, const Node *rhs) const
    {
        return ((lhs->g + lhs->h) > (rhs->g + rhs->h));
    }
};
void printMatrix(int mat[N][N], int g, int h)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
    cout << "g:" << g << " " << "h:" << h << " " << "f:" << g + h << endl;
    cout << endl;
}
void print(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    print(node->parent);
    printMatrix(node->mat, node->g, node->h);
}

void solve(int start[N][N], int goal[N][N], int x, int y)
{
    priority_queue<Node *, vector<Node *>, comp> pq;
    Node *root = newnode(start, 0, x, y, x, y, NULL);
    root->h = heuristic(root->mat, goal);
    pq.push(root);
    int step = 0;
    while (!pq.empty())
    {
        Node *m = pq.top();
        pq.pop();

        if (m->h == 0)
        {
            print(m);
            cout << "steps taken:" << step << endl;
            return;
        }

        step++;
        for (int i = 0; i < 4; i++)
        {
            int dx = m->x + drow[i];
            int dy = m->y + dcol[i];

            if (isSafe(dx, dy))
            {
                Node *node = newnode(m->mat, m->g + 1, m->x, m->y, dx, dy, m);
                node->h = heuristic(node->mat, goal);
                pq.push(node);
            }
        }
    }
}
int main()
{

    int x, y = -1;
    int start[N][N];
    int goal[N][N];

    cout << "enter initial state" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            if (num == 0)
            {
                x = i;
                y = j;
            }
            start[i][j] = num;
        }
    }
    cout << "enter goal state" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;

            goal[i][j] = num;
        }
    }
    solve(start, goal, x, y);
    return 0;
}

// sample input
// initial state - 2 8 3 1 6 4 7 0 5
// final state- 1 2 3 8 0 4 7 6 5

// 2 8 3 1 6 4 7 0 5 1 2 3 8 0 4 7 6 5