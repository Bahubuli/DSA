class Solution {
public:
    
    int dp[501];
    
    int helper(vector<int>&nums,int i,int j,int k)
    {
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i]!=-1) return dp[i];
        
        int ans = 0;
        int mx =0;
        for(int d=i;d<min(i+k,j+1);d++)
        {
            
            mx = max(mx,nums[d]);
            ans = max(ans,(d-i+1)*mx+helper(nums,d+1,j,k));
        }
        
        return dp[i] =  ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& nums, int k) 
    {
        int n = nums.size();
         memset(dp,-1,sizeof(dp));
         return helper(nums,0,n-1,k);
        
        
//         memset(dp,0,sizeof(dp));
        
//         for(int i=0;i<n;i++) dp[i][i] = nums[i];
        
//         for(int i=n-1;i>=0;i--)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(j<=i) continue;
                
//                   int ans = 0;
//                   int mx =0;
//                   for(int d=i;d<min(i+k,j+1);d++)
//                   {

//                       mx = max(mx,nums[d]);
//                       ans = max(ans,(d-i+1)*mx+ dp[d+1][j]);
//                   }

//                    dp[i][j] =  ans;
//             }
//         }
       
//         return dp[0][n-1];
   }
};