// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findKRotation(int arr[], int n)
    {
        // code here
        int start = 0;
        int end = n - 1;
        int mid;
        if (arr[start] <= arr[end])
            return 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[start] <= arr[end])
                return start;

            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
                return mid;

            else if (arr[mid] >= arr[start])
                start = mid + 1;

            else if (arr[mid] < arr[start])
                end = mid - 1;
        }
        return start;
    }
    int search(int arr[], int l, int h, int key)
    {
        int bp = findKRotation(arr, h + 1);
   
        int idx = -1;

        int l1 = l;
        int h1 = bp - 1;
        while (l1 <= h1)
        {
            int mid = l1 + (h1 - l1) / 2;

            if (arr[mid] == key)
            {
                idx = mid;
                return idx;
            }

            else if (arr[mid] < key)
                l1 = mid + 1;

            else
                h1 = mid - 1;
        }
        int l2 = bp;
        int h2 = h;
        while (l2 <= h2)
        {
            int mid = l2 + (h2 - l2) / 2;

            if (arr[mid] == key)
            {
                idx = mid;
                return idx;
            }

            else if (arr[mid] < key)
                l2 = mid + 1;

            else
                h2 = mid - 1;
        }

        return -1;
    }
};

// { Driver Code Starts.
int main()
{

        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;

    return 0;
} // } Driver Code Ends
