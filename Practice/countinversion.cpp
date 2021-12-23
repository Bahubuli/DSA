// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:

    long long merge(long long int arr[], int l, int mid, int r)
    {
        int i = l;
        int j = mid;
        int k = 0;
        int temp[r - l + 1];
        int count = 0;
        while(i<mid && j<=r)
        {
            if(arr[i]<=arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                count = count + mid - i;
            }

        }

        while(i<mid)
        {
            temp[k++] = arr[i++];
        }
        while(j<=r)
        {
            temp[k++] = arr[j++];
        }
        for(int i =l,k=0;i<=r;i++,k++)
        {
        arr[i] = temp[k];
        }
    return count;
    }
    long long mergesort(long long int arr[], int l, int r)
    {
        long long int inv = 0;
        if (l < r)
        {
            int mid = (r + l) / 2;
            inv += mergesort(arr, l, mid);
            inv += mergesort(arr, mid + 1, r);
            inv += merge(arr, l, mid + 1, r);
        }
        return inv;
        }

        long long int inversionCount(long long arr[], long long N)
        {
            // Your Code Here
            long long int ans = mergesort(arr, 0, N);
            return ans;
        }
    };

    // { Driver Code Starts.

    int main()
    {

        long long T;
        cin >> T;

        while (T--)
        {
            long long N;
            cin >> N;

            long long A[N];
            for (long long i = 0; i < N; i++)
            {
                cin >> A[i];
            }
            Solution obj;
            cout << obj.inversionCount(A, N) << endl;
        }

        return 0;
    }
    // } Driver Code Ends
