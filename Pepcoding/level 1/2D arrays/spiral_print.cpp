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

void spiralprint(int **a, int r, int c)
{
    int count = r * c - 1, i = 0, j = 0;
    int jl = 0, il = 0, jh = r - 1, ih = c - 1;
    while (count > 0)
    {
        while (j <= jh)
        {
            cout << a[j][i] << endl;

            count--;
            if (j == jh)
            {
                il = il + 1;
                i = il;
                break;
            }

            j++;
        }
        if (count <= 0)
            break;

        while (i <= ih)
        {
            count--;
            cout << a[j][i] << endl;

            if (i == ih)
            {
                jh = jh - 1;
                j = jh;
                break;
            }
            i++;
        }
        if (count <= 0)
            break;

        while (j >= jl)
        {
            count--;
            cout << a[j][i] << endl;
            ;
            if (j == jl)
            {
                ih = ih - 1;
                i = ih;
                break;
            }
            j--;
        }
        if (count <= 0)
            break;

        while (i >= il)
        {
            count--;
            cout << a[j][i] << endl;

            if (i == il)
            {
                jl = jl + 1;
                j = jl;
                break;
            }
            i--;
        }
        if (count <= 0)
            break;
    }
}

int main()
{
    int r, c;
    cin >> r >> c;

    int **arr = new int *[r];

    for (int i = 0; i < r; i++)
        arr[i] = new int[c];
    takeinput(arr, r, c);
    display(arr, r, c);
    spiralprint(arr, r, c);
}