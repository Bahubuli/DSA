class Solution {
public:
    
    
    int helper(vector<vector<int>> &grid,int idx,int lidx,int ridx,int d,int sign)
    {
        if(d==grid.size())
        {
            
            return idx;
        }
        
        if(idx==0 && grid[d][idx]==-1) return -1;
        if(idx==grid[d].size()-1 && grid[d][idx]==1) return -1;
     
        
        if(grid[d][idx]==1 && grid[d][ridx]==1)
            return helper(grid,idx+1,lidx+1,ridx+1,d+1,1);
        
        if(grid[d][idx]==-1 && grid[d][lidx]==-1)
            return helper(grid,idx-1,lidx-1,ridx-1,d+1,-1);
        
        return -1;    
    }
    
    
   
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        vector<int>ans(grid[0].size(),1);
       
        for(int i=0;i<grid[0].size();i++)
        {
            int res = helper(grid,i,i-1,i+1,0,0);
            
            ans[i]= res;
        }
        return ans;
    }
};