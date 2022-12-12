class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int>dp(46,0);
        dp[0] = 1;
        dp[1] = 1;
        int ans = 0;
        for(int i=2;i<=n;i++)
            dp[i] = dp[i-1]+dp[i-2];
        
        return dp[n];
        
    }
};