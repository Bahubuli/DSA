class Solution {
public:
    int countSquares(vector<vector<int>>& mat) 
    {
        int n = mat.size(),m=mat[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int k=0;k<m;k++) dp[0][k] = mat[0][k];
        for(int k=0;k<n;k++) dp[k][0] = mat[k][0];
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j])
                {
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        
            
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                sum+= dp[i][j];
        }
        return sum;
    }
};