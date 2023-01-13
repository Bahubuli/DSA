class Solution {
public:
    
    int helper(int node,vector<int>adj[],string &s,int &ans)
    {
        int max1 = 0,max2 = 0;
        
        for(auto it:adj[node])
        {
             int res = helper(it,adj,s,ans);
            if(s[node]==s[it]) continue;
             
            if(res>max1)
            {
                max2 = max1;
                max1 = res;
            }
            else if(res>max2) max2 = res;
        }
        
        ans = max(ans,1+max1+max2);
        return 1+max1;
    }
    
    int longestPath(vector<int>& parent, string s) 
    {
        int n = parent.size(),ans=0;
        vector<int>adj[n];
        for(int i=0;i<n;i++) if(parent[i]!=-1) adj[parent[i]].push_back(i);
        helper(0,adj,s,ans);
        return ans;
        
    }
};