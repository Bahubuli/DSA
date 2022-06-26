class Solution {
public:
   long long int helper( int n,vector<long long int> &dp){
    if(n == 1) return dp[n] = 2;
       
    if(n == 2) return dp[n] =  3;
           
    if(dp[n] != -1) return dp[n];
        long long int mod = (1e9+7);
       long long int pick,npick;
       pick = helper(n-2,dp)%mod;
       npick = helper(n-1,dp)%mod;
            
    return dp[n] = (pick+npick)%mod;
}
    
    
    int countHousePlacements(int N) 
    {
     vector<long long int> dp(N+1,-1);
     helper(N,dp);
     long long int mod = (1e9+7);
     return (dp[N]*dp[N])%mod;
        
    }
};