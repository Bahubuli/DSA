class Solution {
public:
    
  
    int recurr(vector<vector<int>>&grid,vector<vector<int>>&zeros,vector<vector<int>>&extras)
    {
       int ans = 999999;
        bool got=false;
        for(int i=0;i<zeros.size();i++)
        {
            if(grid[zeros[i][0]][zeros[i][1]]==0)
            {
                got = true;
               
                for(int j=0;j<extras.size();j++)
                {
                   if(grid[extras[j][0]][extras[j][1]]>1)
                   {
                       
                        
                        grid[zeros[i][0]][zeros[i][1]]=1;
                        grid[extras[j][0]][extras[j][1]]--;
                       
                        int res = recurr(grid,zeros,extras);
                       
                        ans = min(ans,res+(abs(extras[j][0]-zeros[i][0])+abs(extras[j][1]-zeros[i][1])));
                       
                        grid[extras[j][0]][extras[j][1]]++;
                        grid[zeros[i][0]][zeros[i][1]]=0;
                   }   
                }
               
                 
            }
        }
        
        if(!got) return 0;
        return ans;
        
    }
    
    int minimumMoves(vector<vector<int>>& grid) 
    {
        int ans = 0,n=grid.size(),m=grid[0].size();
        
        vector<vector<int>>zeros;
        vector<vector<int>>extras;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    zeros.push_back({i,j});
                
                if(grid[i][j]>1)
                    extras.push_back({i,j});
               
            }
        }
        
        return recurr(grid,zeros,extras);
        
    }
};