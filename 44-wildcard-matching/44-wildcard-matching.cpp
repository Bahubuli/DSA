class Solution {
public:
    bool isMatch(string s1, string s2) 
    {
   int n = s1.size(),m=s2.size();
   vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
    dp[n][m] = true;  
    
        
    for(int j=m-1;j>=0 && s2[j]=='*';j--)
    {
       dp[n][j] = true;
    } 
        
    //cout<<dp[2][1]<<endl;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(s2[j]=='*') dp[i][j] = dp[i+1][j]+dp[i][j+1];
            else if(s2[j]=='?' || s1[i]==s2[j]) dp[i][j] = dp[i+1][j+1];
            
        }
    }

      return dp[0][0];  
        
    }
};