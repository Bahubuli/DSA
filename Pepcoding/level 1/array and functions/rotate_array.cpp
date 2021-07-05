#include <iostream>
using namespace std;
// O(n2) solution with O(1) space complexity
void rotate(long long int *arr, long long int n, long long int k)
{
    // write your code here
    k = k % n;
    while (k < 0)
        k = k + n;
    long long int temp, i, j;
    for (j = 0; j < k; j++)
    {
        temp = arr[n - 1];
        for (i = n - 2; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = temp;
    }
}
// O(n) solution with O(k) space complexity
void rotate2(long long int *arr, long long int n, long long int k)
{
    // write your code here
    k = k % n;
    while (k < 0)
        k = k + n;
    long long int temp, i, j;
    long long int *krr = new long long int[k];
    j = n - 1;
    for (i = k - 1; i >= 0; i--)
    {
        krr[i] = arr[j];
        j--;
    }
    for (j = n - 1; j - k >= 0; j--)
    {
        arr[j] = arr[j - k];
    }
    i = 0;
    for (j = 0; j < k; j++)
    {
        arr[j] = krr[i];
        i++;
    }
}

//

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    long long int n, r, i;
    cin >> n;
    long long int *arr = new long long int[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> r;

    rotate2(arr, n, r);

    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
/* implement reverse method in future   
 reverse(arr,0,n - 1);
    reverse(arr,0 , k - 1);
    reverse(arr,k ,n - 1);
    */