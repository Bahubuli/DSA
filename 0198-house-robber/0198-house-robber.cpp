class Solution {
public:
    
    int helper(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i>=nums.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        return dp[i] = max(helper(nums,i+2,dp)+nums[i], 
                          helper(nums,i+1,dp));
    }
    
    int rob(vector<int>& nums) 
    {
        vector<int>dp(nums.size()+1,0);
        int n = nums.size();
        dp[n] = 0;
        dp[n-1] = nums[n-1];
        
        for(int i=n-2;i>=0;i--)
            dp[i] = max(dp[i+2]+nums[i], dp[i+1]);
        
        
        return dp[0];
        
        
        
        
    }
};