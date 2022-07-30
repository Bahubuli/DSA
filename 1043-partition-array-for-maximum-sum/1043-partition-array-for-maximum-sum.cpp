class Solution {
public:
    
    int dp[501][501];
    
    int helper(vector<int>&nums,int i,int j,int k)
    {
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 0;
        int mx =0;
        for(int d=i;d<min(i+k,j+1);d++)
        {
            
            mx = max(mx,nums[d]);
            ans = max(ans,(d-i+1)*mx+helper(nums,d+1,j,k));
        }
        
        return dp[i][j] =  ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& nums, int k) 
    {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return helper(nums,0,n-1,k);
    }
};