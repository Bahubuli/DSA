class Solution {
public:
    
    int dfs(vector<vector<int>>&grid,int i,int j)
    {
         int n=grid.size(),m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m ||  grid[i][j]==0) return 0;
        
        grid[i][j] = 0;
        
        int l = dfs(grid,i,j-1);
        int r = dfs(grid,i,j+1);
        int d = dfs(grid,i+1,j);
        int t = dfs(grid,i-1,j);
        
        return l+r+d+t+1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        int maxarea = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int area = dfs(grid,i,j);
                    maxarea= max(area,maxarea);
                }
            }
        }
        return maxarea;
        
    }
};