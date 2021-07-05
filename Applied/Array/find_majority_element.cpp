#include <bits/stdc++.h>
using namespace std;

int findmajority1(int arr[], int n)
{
    int num = -1, count = 0, counter = 0, number = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                num = arr[i];
            }
        }
        if (count >= counter)
        {
            counter = count;
            number = num;
        }
    }
    return number;
}
//not exactly hashing but O(n) solution
int findmajority2(int arr[], int n)
{
    int a, b, max = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int *idx = new int[max]();
    for (int i = 0; i < n; i++)
    {
        idx[arr[i]]++;
    }
    int num = 0;
    for (int i = 0; i < max; i++)
    {
        if (idx[i] > num)
            num = i;
    }
    return num;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << " the majority number is: " << findmajority2(arr, n);
}
