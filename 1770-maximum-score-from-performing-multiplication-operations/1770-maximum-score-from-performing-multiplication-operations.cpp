class Solution {
public:
    int dp[1001][1001];
    int helper(vector<int>&nums, vector<int>&mults,int l,int r,int i,int m)
    {
        int n = nums.size();
       if(i==m) return 0;
        
        
       
        if(dp[l][r]!=-1e9) return dp[l][r];
        int pickl = nums[l]*mults[i] + helper(nums,mults,l+1,r,i+1,m);
        int pickr = nums[n-r]*mults[i] + helper(nums,mults,l,r+1,i+1,m);
        
        return dp[l][r] = max(pickl,pickr);
        
    }
    int maximumScore(vector<int>& nums, vector<int>& mults) 
    {
        for(int i=0;i<1001;i++)
            for(int j=0;j<1001;j++)
                dp[i][j] = -1e9;
        
        return helper(nums,mults,0,1,0,mults.size());
    }
};