class Solution {
public:
    int helper(vector<int>&prices,int i,int cp,vector<vector<int>>&dp)
    {
        if(i>=prices.size()) return 0;
        if(dp[i][cp]!=-1) return dp[i][cp];
        if(cp==0) return dp[i][cp]= max(-prices[i]+helper(prices,i+1,1,dp), helper(prices,i+1,0,dp));
        else return dp[i][cp] = max(prices[i]+helper(prices,i+2,0,dp),helper(prices,i+1,1,dp));
    }
    int maxProfit(vector<int>& prices) 
    {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return helper(prices,0,0,dp);
    }
};