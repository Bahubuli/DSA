class Solution {
public:
    int helper(vector<int>&nums,int t,vector<int>&dp)
    {
        //cout<<t<<endl;
        int n = nums.size();
        if(t==0) return 1;
        if(t<0) return 0;
        if(dp[t]!=-1) return dp[t];
        
        int ans = 0;
        
        for(auto x:nums)
        {
            ans+= helper(nums,t-x,dp);
        }
        
        return dp[t] = ans;
        
    }
    
    
    int combinationSum4(vector<int>& nums, int t) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(t+1,-1);
        
        return helper(nums,t,dp);
        
    }
};