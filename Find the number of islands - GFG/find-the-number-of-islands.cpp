//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(vector<vector<char>>&grid,int i,int j,vector<vector<int>>&vis)
    {
        int n =grid.size(), m = grid[0].size();
        if(i>=n || i<0 || j>=m || j<0 || vis[i][j] || grid[i][j]=='0') return;
        
        vis[i][j] = 1;
        dfs(grid,i+1,j,vis);
        dfs(grid,i,j+1,vis);
        dfs(grid,i-1,j,vis);
        dfs(grid,i,j-1,vis);
        
        dfs(grid,i+1,j+1,vis);
        dfs(grid,i-1,j-1,vis);
        dfs(grid,i-1,j+1,vis);
        dfs(grid,i+1,j-1,vis);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
         int n =grid.size(), m = grid[0].size(),ans=0;
         vector<vector<int>>vis(n,vector<int>(m,0));
         
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(!vis[i][j] && grid[i][j] =='1')
                 {
                     ans++;
                     dfs(grid,i,j,vis);
                 }
             }
         }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends