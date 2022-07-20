class Solution {
public:
    
    void helper(vector<vector<string>>&ans,vector<string>&ds,vector<int>&rs,vector<int>&udg,vector<int>&ldg,int r,int n)
    {
        if(r==n)
        {
            ans.push_back(ds);
            return;
        }
        for(int c=0;c<n;c++)
        {
            if(rs[c]==0 && udg[r+c]==0 && ldg[n-1-r+c]==0)
            {
                rs[c]=1;
                udg[r+c]=1;
                ldg[n-1-r+c]=1;
                ds[c][r]='Q';
                helper(ans,ds,rs,udg,ldg,r+1,n);
                ds[c][r]='.';
                rs[c]=0;
                udg[r+c]=0;
                ldg[n-1-r+c]=0;
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) 
    {
        string s(n,'.');
        vector<string>ds(n,s);
        vector<vector<string>>ans;
        
        vector<int>rows(n,0);
        vector<int>upperdiag(2*n-1,0);
        vector<int>lowerdiag(2*n-1,0);
        
        helper(ans,ds,rows,upperdiag,lowerdiag,0,n);
        return ans;
        
        
    }
};