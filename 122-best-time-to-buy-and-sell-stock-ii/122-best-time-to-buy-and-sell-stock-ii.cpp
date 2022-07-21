class Solution {
public:
    
    int helper(vector<int>&values,int n,int i,bool buy,vector<vector<int>>&dp)
    {
    if(i==n) return 0;
    int pick,npick;
    if(dp[i][(int)buy]!=-1) return dp[i][(int)buy];
    if(buy)
    {
        pick = -values[i]+helper(values,n,i+1,!buy,dp);
        npick = helper(values,n,i+1,buy,dp);  
    }
    else
    {
        pick = values[i]+helper(values,n,i+1,!buy,dp);
        npick = helper(values,n,i+1,buy,dp);  
    }
    return dp[i][(int)buy] = max(pick,npick);
    }
    
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(prices,n,0,true,dp);
        
    }
};