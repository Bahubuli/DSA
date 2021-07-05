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

void diagonaltrs(int **a, int r, int c)
{

    int i = 0, j = 0, k = 0;
    while (j < c)
    {
        k = j;
        i = 0;
        while (k < c)
        {
            cout << a[i][k] << endl;
            i++;
            k++;
        }

        j++;
    }
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