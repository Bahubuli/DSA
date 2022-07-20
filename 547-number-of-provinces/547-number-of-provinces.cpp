class Solution {
public:
    
    void dfs(vector<vector<int>>&grid,int i,int j)
    {
        int n = grid.size();
        if(i>=n || j>=n || i<0 || j<0 || grid[i][j]==0) return;
        
        grid[i][j]=0;
        for(int k=0;k<n;k++)
        {
            if(k!=i && grid[j][k]==1) dfs(grid,j,k);
        }
       
    }
    
    int findCircleNum(vector<vector<int>>& grid) 
    {
        int n = grid.size(),ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j);
                    ans++;
                }
                
            }
        }
        return ans;
        
    }
};