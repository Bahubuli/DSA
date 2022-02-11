#include <bits/stdc++.h>
using namespace std;

void display(int **a, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

void takeinput(int **a, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
    }
}

bool ismin(int **a, int r, int c, int i, int j)
{
    int x = a[i][j];

    for (j = 0; j < c; j++)
    {
        if (x > a[i][j])
            return false;
    }
    return true;
}

bool ismax(int **a, int r, int c, int i, int j)
{
    int x = a[i][j];

    for (i = 0; i < c; i++)
    {
        if (x < a[i][j])
            return false;
    }
    return true;
}
void diagonaltrs(int **a, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (ismax(a, r, c, i, j) && ismin(a, r, c, i, j))
            {
                cout << a[i][j];
                return;
            }
        }
    }
    cout << "Invalid input";
}

int main()
{
    int r, c, s, t;
    cin >> r;
    c = r;

    int **arr = new int *[r];

    for (int i = 0; i < r; i++)
        arr[i] = new int[c];
    takeinput(arr, r, c);

    //display(arr, r, c);
    diagonaltrs(arr, r, c);
    //display(arr, r, c);
}