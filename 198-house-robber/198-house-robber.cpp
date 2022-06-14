class Solution {
public:
    
    int robb(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i>=nums.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
      
        return dp[i] = max(robb(nums,i+1,dp),nums[i]+robb(nums,i+2,dp));
        
        
    }
    
    int rob(vector<int>& nums) 
    {
        int ans = 0;
        vector<int> dp(nums.size()+1,-1);
        return robb(nums,0,dp);
        
    }
};