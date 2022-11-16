class Solution {
public:
    
    int dfs(vector<vector<int>>&stones,int idx,vector<bool>&vis)
    {
        int n = vis.size(),ans=0;
        
        vis[idx] = true;
        
        for(int i=0;i<n;i++)
            if(!vis[i] && (stones[i][0]==stones[idx][0] || stones[i][1]==stones[idx][1]))
                ans+= 1+dfs(stones,i,vis);
        
        
        return ans;
        
    }
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size(),ans=0;
        vector<bool>vis(n,0);    
        
        for(int i=0;i<n;i++)
            if(!vis[i]) ans+= dfs(stones,i,vis);
        
        return ans;
    }
};