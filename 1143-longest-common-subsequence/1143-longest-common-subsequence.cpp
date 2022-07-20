class Solution {
public:
    
   
    
    int longestCommonSubsequence(string s1, string s2) 
    {
        
        int n = s1.size(),m =s2.size();
        if(m>n) return longestCommonSubsequence(s2,s1);
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++) dp[0][i] = (s1[0]==s2[i]);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int match =(s1[i]==s2[j]),nmatch = 0;
                if(match && j>0) match+= dp[i-1][j-1];
                
                nmatch = max(nmatch,dp[i-1][j]);
                if(j>0) nmatch = max(nmatch,dp[i][j-1]);
                
                dp[i][j] = max(match,nmatch);
            }
        }
        
        //for(int i=0;i<m;i++) cout<<dp[0][i]<<endl;
       return dp[n-1][m-1];
        
    }
};