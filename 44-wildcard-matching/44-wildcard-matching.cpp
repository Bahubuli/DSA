class Solution {
public:
    bool isMatch(string s1, string s2) 
    {
         int n = s1.size(),m=s2.size();
   vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
    dp[0][0] = true;  
    
    for(int j=0;j<m && s2[j]=='*';j++)
        dp[0][j+1] = true;
        
        
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s2[j-1]=='*') dp[i][j] = dp[i-1][j]+dp[i][j-1];
            else if(s1[i-1]==s2[j-1] || s2[j-1]=='?') dp[i][j] = dp[i-1][j-1];
        }
    }
      return dp[n][m];  
        
    }
};