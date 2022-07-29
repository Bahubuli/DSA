class Solution {
public:
    
    int helper(vector<int>&cuts,int i,int j, vector<vector<int>>&dp)
    {
        int res = 1e9;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        for(int k=i;k<=j;k++)
            res = min(res,cuts[j+1]-cuts[i-1]+helper(cuts,i,k-1,dp)+helper(cuts,k+1,j,dp));
        
        return dp[i][j] = res==1e9 ? 0 : res;
    }
    
    
    int minCost(int n, vector<int>& cuts) 
    {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(m+3,vector<int>(m+3,-1));
        return helper(cuts,1,m,dp);
    }
};