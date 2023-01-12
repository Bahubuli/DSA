class Solution {
public:
   
    void createGraph(vector<vector<int>>&edges,vector<int>adj[])
        {
            for(auto e:edges)
            {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
        }
        
    
    int dfs(int node,int ans,vector<bool>&vis,vector<bool>&apple,vector<int>adj[])
    {
        if(vis[node]) return 0;
        vis[node] = true;
        
        int res = 0;
        
        for(auto adjnode:adj[node])
            res+= dfs(adjnode,2,vis,apple,adj);
        
        if(res==0 && !apple[node]) return 0;
        
        return ans+res;
    }
    
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<int>adj[n];
        vector<bool>vis(n,0);
        createGraph(edges,adj);
        return dfs(0,0,vis,hasApple,adj);
    }
};