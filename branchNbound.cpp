#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &board, vector<vector<string>> &result, vector<bool> &dig1, vector<bool> &dig2, vector<bool> &cols, int row, int n)
{
    if (row == n)
    {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (!dig1[row - col + n - 1] && !cols[col] && !dig2[row + col])
        {
            board[row][col] = 'Q';
            dig1[row - col + n - 1] = cols[col] = dig2[row + col] = true;
            solve(board, result, dig1, dig2, cols, row + 1, n);
            board[row][col] = '.';
            dig1[row - col + n - 1] = cols[col] = dig2[row + col] = false;
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
    vector<bool> dig1(2 * n - 1, false);
    vector<bool> dig2(2 * n - 1, false);
    vector<bool> cols(n, false);
    solve(board, result, dig1, dig2, cols, 0, n);
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