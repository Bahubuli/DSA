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
        
    int dfs(int node,int cost,vector<bool>&vis,vector<bool>&hasApple,vector<int>adj[])
    {
        if(vis[node]) return 0;
        vis[node] = 1;
        
        int res = 0;
        for(auto it:adj[node])
            res+=dfs(it,2,vis,hasApple,adj);
        
        if(res==0 && !hasApple[node]) return 0;
        
        return cost+res;
        
    }
    
    
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<int>adj[n];
        vector<bool>vis(n,0);
        createGraph(edges,adj);
        return dfs(0,0,vis,hasApple,adj);
    }
};