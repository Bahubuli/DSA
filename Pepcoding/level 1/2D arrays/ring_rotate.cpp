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

void ring_rotate(int **a, int r, int c, int s, int t)
{
    int il, ih, jl, jh;
    il = 0 + s - 1;
    ih = r - s + 1;
    jl = 0 + s - 1;
    jh = c - s + 1;
    int d = 2 * (jh - jl - 1) + 2 * (ih - il - 1);

    //cout << d << endl;
    t = t % d;
    if (t < 0)
        t = t + d;

    while (t)
    {
        int oo = a[il][jl];

        for (int j = jl; j < jh - 1; j++)
        {

            a[il][j] = a[il][j + 1];
        }

        for (int i = il; i < ih - 1; i++)
        {

            a[i][jh - 1] = a[i + 1][jh - 1];
        }

        for (int j = jh - 1; j > jl; j--)
        {

            a[ih - 1][j] = a[ih - 1][j - 1];
        }

        for (int i = ih - 1; i > il; i--)
        {

            a[i][jl] = a[i - 1][jl];
        }
        a[il + 1][jl] = oo;

        t--;
    }
}

int main()
{
    int r, c, s, t;
    cin >> r >> c;

    int **arr = new int *[r];

    for (int i = 0; i < r; i++)
        arr[i] = new int[c];
    takeinput(arr, r, c);
    cin >> s >> t;
    //display(arr, r, c);
    ring_rotate(arr, r, c, s, t);
    display(arr, r, c);
}