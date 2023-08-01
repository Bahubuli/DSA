class Solution {
public:
    
    void helper(vector<vector<int>>&ans,vector<int>&res,int i,int n,int k)
    {
        //cout<<i<<" "<<n<<" "<<k<<endl;
        
        if(k==0)
        {
            ans.push_back(res);
            return;
        }
        if(i>n) return;
        helper(ans,res,i+1,n,k);
        res.push_back(i);
        helper(ans,res,i+1,n,k-1);
        res.pop_back();
            
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>>ans;
        vector<int>res;
        helper(ans,res,1,n,k);
        return ans;
        
    }
};