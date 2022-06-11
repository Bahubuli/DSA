class Solution {
public:
    int coinChange(vector<int>& coins, int n) 
    {
        int dp[n+1];
        dp[0] = 0;
        int ans;
        for(int i=1;i<=n;i++)
        {
            dp[i] = INT_MAX;
            for(int c:coins)
            {
                if(i-c<0) continue;
                
                if(dp[i-c]!=INT_MAX) dp[i] = min(dp[i-c]+1,dp[i]);
            }
        }
        return dp[n]==INT_MAX ? -1 : dp[n];
    }
};