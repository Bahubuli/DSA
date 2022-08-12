class Solution {
public:
    
    int helper(vector<int>&nums,int i,int sum,int t,vector<unordered_map<int,int>>&dp)
    {
        int n = nums.size();
        if(i==n)
        {
            if(sum==t) return 1;
            else return 0;
        }
        if(dp[i].find(sum)!=dp[i].end()) return dp[i][sum];
        
        return dp[i][sum] =  helper(nums,i+1,sum+nums[i],t,dp)+helper(nums,i+1,sum-nums[i],t,dp);
    }
    
    int findTargetSumWays(vector<int>& nums, int t) 
    {
         int n = nums.size();
        vector<unordered_map<int,int>>dp(n);
        return helper(nums,0,0,t,dp);
        
    }
};