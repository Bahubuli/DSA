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

int main()
{
    int r, c;
    cin >> r >> c;

    int **arr = new int *[r];

    for (int i = 0; i < r; i++)
        arr[i] = new int[c];
    takeinput(arr, r, c);
    int j = 0;
    for (int i = 0; i < c; i++)
    {

        if (j == 0)
        {
            while (j < r)
            {
                cout << arr[j][i] << " ";

                j++;
            }
        }
        else
        {

            while (j >= 0)
            {
                cout << arr[j][i] << " ";

                j--;
            }
        }
        cout << "\n";

        if (i % 2 == 0)
            j--;
        else
            j++;
    }
}