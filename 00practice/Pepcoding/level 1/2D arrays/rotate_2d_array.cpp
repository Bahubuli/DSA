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
void swap(int **x, int **y)
{
    int temp = **x;
    **x = **y;
    **y = temp;
}

void rotate(int **a, int r, int c)
{
    int i = 0, j = 0, k = c - 1;

    while (j < k)
    {
        swap(a[i][j], a[i][k]);
        i++;
        if (i == r)
        {
            i = 0;
            j++;
            k--;
        }
    }
    //display(a, r, c);
    int x = 1, temp;
    i = 0;
    j = c - 1;

    while (i < r)
    {

        temp = a[i][j - x];
        a[i][j - x] = a[i + x][j];
        a[i + x][j] = temp;

        x++;
        if (j - x == -1)
        {
            i++;
            j--;
            x = 0;
        }
        //cout << "++++++++++++++++++++" << endl;
        //display(a, r, c);
    }
}

int main()
{
    int r, c;
    cin >> r;
    c = r;

    int **arr = new int *[r];

    for (int i = 0; i < r; i++)
        arr[i] = new int[c];
    takeinput(arr, r, c);
    //display(arr, r, c);
    rotate(arr, r, c);
    display(arr, r, c);
}