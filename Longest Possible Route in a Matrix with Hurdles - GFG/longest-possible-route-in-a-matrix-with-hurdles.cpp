// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    int helper(vector<vector<int>>arr,int r,int c,int i,int j,int xd,int yd)
    {
        if(i<0 || i>=r || j<0 || j>=c || arr[i][j]==0) return -INT_MAX/2;
        
        if(i==xd && j==yd) return 0;
        
        arr[i][j] = 0;
        
        int m = helper(arr,r,c,i+1,j,xd,yd);
        int n = helper(arr,r,c,i,j+1,xd,yd);
        int o = helper(arr,r,c,i-1,j,xd,yd);
        int p = helper(arr,r,c,i,j-1,xd,yd);
        
        return 1+max(max(p,o),max(m,n));
    }
    
    int longestPath(vector<vector<int>> mat, int xs, int ys, int xd, int yd)
    {
        int r = mat.size();
        int c = mat[0].size();
        
        int ans  = helper(mat,r,c,xs,ys,xd,yd);
        return ans<0 ? -1 : ans;
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
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends