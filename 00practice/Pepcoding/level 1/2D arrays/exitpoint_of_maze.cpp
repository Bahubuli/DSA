// unreadable code try again with much easier solution
// sumit sir's solution
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

void exitpoint(int **a, int r, int c)
{
    int i = 0, j = 0, flag = 0;
    while (flag == 0)
    {

        while (flag == 0)
        {

            if (j == c - 1 && a[i][j] == 0)
            {
                flag = 1;
                break;
            }
            if (a[i][j] == 1)
            {
                i = i + 1;
                break;
            }

            j++;
        }

        while (flag == 0)
        {

            if (i == r - 1 && a[i][j] == 0)
            {
                flag = 1;
                break;
            }
            if (a[i][j] == 1)
            {
                j = j - 1;
                break;
            }
            i++;
        }

        while (flag == 0)
        {

            if (j == 0 && a[i][j] == 0)
            {
                flag = 1;
                break;
            }
            if (a[i][j] == 1)
            {
                i = i - 1;
                break;
            }
            j--;
        }

        while (flag == 0)
        {

            if (i == 0 && a[i][j] == 0)
            {
                flag = 1;
                break;
            }
            if (a[i][j] == 1)
            {
                j = j + 1;
                break;
            }
            i--;
        }
    }
    cout << i << "\n"
         << j << endl;
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
    exitpoint(arr, r, c);
}