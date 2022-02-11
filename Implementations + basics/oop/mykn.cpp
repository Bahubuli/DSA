#include <bits/stdc++.h>
using namespace std;

void displayboard(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void knightspath(vector<vector<int>> board, int r, int c, int move)
{
    if (r < 0 || c < 0 || r >= board.size() || c >= board.size() || board[r][c] > 0)
        return;
    else if (move == board[0].size() * board[0].size())
    {
        board[r][c] = move;
        displayboard(board);
        board[r][c] = 0;
        return;
    }
    board[r][c] = move;

    knightspath(board, r - 2, c + 1, move + 1);

    knightspath(board, r - 1, c + 2, move + 1);

    knightspath(board, r + 1, c + 2, move + 1);

    knightspath(board, r + 2, c + 1, move + 1);

    knightspath(board, r + 2, c - 1, move + 1);

    knightspath(board, r + 1, c - 2, move + 1);

    knightspath(board, r - 1, c - 2, move + 1);

    knightspath(board, r - 2, c - 1, move + 1);

    board[r][c] = 0;
}

int main()
{

    int n, r, c;
    cin >> n >> r >> c;
    vector<vector<int>> board(n, vector<int>(n, 0));

    knightspath(board, r, c, 1);
}
