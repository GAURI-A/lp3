#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int x, int y, int n)
{
    for (int row = 0; row < x; row++)
    {
        if (board[row][y])
        {
            return false;
        }
    }

    int row = x;
    int col = y;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col])
        {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (board[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

void printBoard(vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
            {
                cout << "[Q]";
            }
            else
            {
                cout << "[]";
            }
        }
        cout << endl;
    }

    cout << endl;
}

void solvenqueen(vector<vector<int>> &board, int i, int n)
{
    if (i == n)
    {
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1;
            solvenqueen(board, i + 1, n);
            board[i][col] = 0;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solvenqueen(board, 0, n);
    return 0;
}