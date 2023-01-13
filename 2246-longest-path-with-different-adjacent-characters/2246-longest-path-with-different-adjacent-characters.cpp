class Solution {
public:

    int helper(vector<int>adj[],int node,string &s,int &ans)
    {
        int max1=0,max2=0;
        
        for(auto adjnode:adj[node])
        {
            int res = helper(adj,adjnode,s,ans);
            if(s[node]==s[adjnode]) continue;
            if(res>max1)
            {
                max2 = max1;
                max1 = res;
            }
            else if(res>max2)
            {
                max2 = res;
            }
        }
        
        ans = max(ans,1+max1+max2);
        return 1+max1;
    }
    
    int longestPath(vector<int>& parent, string s) 
    {
        int n = parent.size();
        vector<int>adj[n];
        
        for(int i=0;i<n;i++)
        {
            if(parent[i]!=-1)
            {
                adj[parent[i]].push_back(i);
                
            }
        }
        int ans = 0;
        helper(adj,0,s,ans);
        return ans;
        
    }
};