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

    int **arr1 = new int *[r];

    for (int i = 0; i < r; i++)
        arr1[i] = new int[c];
    takeinput(arr1, r, c);
    int r2, c2;
    cin >> r2 >> c2;

    int **arr2 = new int *[r2];

    for (int i = 0; i < r2; i++)
        arr2[i] = new int[c2];

    takeinput(arr2, r2, c2);
    int s = 0;

    if (c == r2)
    {
        int **arr3 = new int *[r];

        for (int i = 0; i < r; i++)
            arr3[i] = new int[c2];

        for (int k = 0; k < r; k++)
        {
            for (int i = 0; i < c2; i++)
            {
                s = 0;
                for (int j = 0; j < r2; j++)
                {
                    s = s + arr1[k][j] * arr2[j][i];
                }

                arr3[k][i] = s;
            }
        }
        display(arr3, r, c2);
    }
    else
        cout << "Invalid Input";

    // display(arr1, r, c);
    // display(arr2, r2, c2);

    //display(arr, r2, c2);
}