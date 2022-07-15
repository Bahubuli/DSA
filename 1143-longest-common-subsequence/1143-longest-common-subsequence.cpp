class Solution {
public:
    
    int lcs(string &s1,string &s2,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=s1.size() || j>=s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int match = s1[i]==s2[j];
        if(match) match+=lcs(s1,s2,i+1,j+1,dp);
        
        int nmatch = max(lcs(s1,s2,i,j+1,dp),lcs(s1,s2,i+1,j,dp));
        
        return dp[i][j] = max(match,nmatch);
    }
    
    int longestCommonSubsequence(string s1, string s2) 
    {
        
        int n = s1.size(),m =s2.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int match =(s1[i]==s2[j]),nmatch = 0;
                if(match && j>0 && i>0) match+= dp[i-1][j-1];
                
                if(i>0) nmatch = max(nmatch,dp[i-1][j]);
                if(j>0) nmatch = max(nmatch,dp[i][j-1]);
                
                dp[i][j] = max(match,nmatch);
            }
        }
        
       
       return dp[n-1][m-1];
        
    }
};