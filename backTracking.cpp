#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<string> &board, int col, int row, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }
    for (int r = row, c = col; r >= 0 && c < n; r--, c++)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void solve(vector<string> &board, vector<vector<string>> &result, int row, int n)
{
    if (row == n)
    {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, col, row, n))
        {
            board[row][col] = 'Q';
            solve(board, result, row + 1, n);
            board[row][col] = '.';
        }
    }
}

int main()
{

    int n;
    cout << "Enter N" << endl;
    cin >> n;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> result;
    solve(board, result, 0, n);
    for (auto const &sol : result)
    {
        for (auto const &row : sol)
        {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}