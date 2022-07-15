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
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        
        
        
        return lcs(s1,s2,0,0,dp);
        
    }
};