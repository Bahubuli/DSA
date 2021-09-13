
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int matSearch(vector<vector<int>> &mat, int N, int M, int x)
    {
        // your code here
        int l = mat[0].size() - 1;
        int d = 0;

        while (d < mat.size() && l >= 0)
        {
            if (mat[d][l] == x)
                return 1;
            else if (mat[d][l] > x)
            {
                l--;
            }
            else if (mat[d][l] < x)
            {
                d++;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        int x;
        cin >> x;
        Solution ob;
        cout << ob.matSearch(arr, n, m, x) << endl;
    }
} // } Driver Code Ends
