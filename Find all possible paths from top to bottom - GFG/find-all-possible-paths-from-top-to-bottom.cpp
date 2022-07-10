// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
     vector<vector<int>>ans;
   void pathfind(int i,int j,vector<vector<int>>grid, vector<int>& curr){
       int n = grid.size();
       int m =grid[0].size();
       
       if(i == n-1 && j == m-1){
           curr.push_back(grid[i][j]);
           ans.push_back(curr);
           curr.pop_back();
           return;
       }
       curr.push_back(grid[i][j]);
       if(i<n-1) pathfind(i+1,j,grid,curr);
       if(j<m-1) pathfind(i,j+1,grid,curr);
       curr.pop_back();
   }
   vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
   {
       // code here
       ans.clear();
       vector<int> curr;
       pathfind(0,0,grid,curr);
       return ans;
       
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends