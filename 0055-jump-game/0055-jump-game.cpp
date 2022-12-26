class Solution {
public:
    bool helper(vector<int>&nums,int i,vector<int>&dp,bool &ans)
    {
        if(i>=nums.size()-1 || ans) return true;
        
        bool res = false;
        if(dp[i]!=-1) return dp[i];
        if(nums[i]==0) return res;
        
        for(int j=nums[i];j>0;j--)
        {
            res+= helper(nums,i+j,dp,ans);
            if(res) return dp[i] =res;
        }
            
        
        return dp[i] = res;
    }
    
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        bool ans = false;
        vector<int>dp(n+1,-1);
        return helper(nums,0,dp,ans);
    }
};