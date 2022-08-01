class Solution {
public:
    
    void dfs(int node,int dist,vector<int>&edges,vector<int>&dp)
    {
        while(node!=-1 && dp[node]==-1)
        {
            dp[node] = dist++;
            node = edges[node];
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();
        vector<int>dp1(n,-1),dp2(n,-1);
        
        int mind = INT_MAX,ans=-1;
        
        dfs(node1,0,edges,dp1);
        dfs(node2,0,edges,dp2);
        
        for(int i=0;i<n;i++)
        {
            if(min(dp1[i],dp2[i])>=0 && max(dp1[i],dp2[i])<mind)
            {
                mind = max(dp1[i],dp2[i]);
                ans = i;
            }
        }
        return ans;
    }
};