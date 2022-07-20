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

void search(int **a, int r, int c, int x)
{
    //cout << "function starts" << endl;
    int i, j = 0, flag = 0;
    for (i = 0; i < r - 1; i++)
    {
        //cout << " i = " << i << " j =" << j << endl;
        if (x == a[i][j])
        {
            flag = 1;
            break;
        }
        if ((i < r - 2 && x > a[i][j] && x < a[i + 1][j]) || i == r - 1)
            break;
    }

    for (j = 0; j < c; j++)
    {
        //cout << " i = " << i << " j =" << j << endl;
        if (x == a[i][j])
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        cout << i << "\n"
             << j << endl;
    }
    else
        cout << "Not Found" << endl;
}

int main()
{
    int r, c, x;
    cin >> r;
    c = r;

    int **arr = new int *[r];

    for (int i = 0; i < r; i++)
        arr[i] = new int[c];
    takeinput(arr, r, c);
    cin >> x;
    //display(arr, r, c);
    search(arr, r, c, x);
    //display(arr, r, c);
}