class Solution {
public:
    
    int lcs(string s1, string s2)
    {
        if(s1.size()<s2.size()) return lcs(s2,s1);
        
        int n = s1.size() , m = s2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int match = s1[i]==s2[j],nmatch = 0;
                if(i>0 && j>0 && match) match+= dp[i-1][j-1];
                
                if(i>0) nmatch = max(nmatch,dp[i-1][j]);
                if(j>0) nmatch = max(nmatch,dp[i][j-1]);
                
                dp[i][j] = max(match,nmatch);
            }
        }
        return dp[n-1][m-1];
    }
    
    int minInsertions(string s) 
    {
        
        string rs = s;
        reverse(rs.begin(),rs.end());
        return s.size()-lcs(s,rs);
    }
};