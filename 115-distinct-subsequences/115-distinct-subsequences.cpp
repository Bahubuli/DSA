class Solution {
public:
    int mod = 1e9+7;
    int subc(string &s, string &t) 
{
    int n = s.size(),m = t.size();
    vector<vector<unsigned int>>dp(n+1,vector<unsigned int>(m+1,0));
    
    for(int k=0;k<=n;k++) dp[k][0]=1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int match = s[i-1]==t[j-1];
            
            if(match) match= dp[i-1][j-1];
            
            int notmatch = dp[i-1][j];
            
            dp[i][j] = (match+notmatch)%mod;
        }
    }
    
    return dp[n][m];
   
}
    
    int numDistinct(string s, string t) 
    {
        return subc(s,t);
    }
};