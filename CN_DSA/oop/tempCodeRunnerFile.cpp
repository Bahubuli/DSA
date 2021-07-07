
#include <iostream>
#include <cmath>
    typedef long long int ll;
#include <bits/stdc++.h>
using namespace std;
void printknightstour(vector<vector<int>> chess, int r, int c, int move);
void displayboard(vector<vector<int>> chess);

int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    vector<vector<int>> chess(n, vector<int>(n));

    printknightstour(chess, r, c, 1);
}

void printknightstour(vector<vector<int>> chess, int r, int c, int move)
{
    if (r < 0 || c < 0 || r >= chess.size() || c >= chess.size() || chess[r][c] > 0)
    {
        return;
    }
    else if (move == chess.size() * chess.size())
    {
        chess[r][c] = move;
        displayboard(chess);
        chess[r][c] = 0;
        return;
    }
    chess[r][c] = move;
    printknightstour(chess, r - 2, c + 1, move + 1);
    printknightstour(chess, r - 1, c + 2, move + 1);
    printknightstour(chess, r + 1, c + 2, move + 1);
    printknightstour(chess, r + 2, c + 1, move + 1);
    printknightstour(chess, r + 2, c - 1, move + 1);
    printknightstour(chess, r + 1, c - 2, move + 1);
    printknightstour(chess, r - 1, c - 2, move + 1);
    printknightstour(chess, r - 2, c - 1, move + 1);
    chess[r][c] = 0;
}

void displayboard(vector<vector<int>> chess)
{
    for (int i = 0; i < chess.size(); i++)
    {
        for (int j = 0; j < chess[0].size(); j++)
        {
            cout << (chess[i][j] + " ");
        }
        cout << "\n";
    }
    cout << "\n";
}
