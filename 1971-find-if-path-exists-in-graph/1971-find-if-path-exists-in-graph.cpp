class Solution {
public:
    
    bool dfs(vector<vector<int>>&edges,vector<bool>&vis,int s,int d)
    {
        if(s==d) return true;
        
        if(vis[s]) return false;
        
        vis[s] = true;
        
        bool ans = false;
        
        for(int adj:edges[s])
                ans = ans + dfs(edges,vis,adj,d); 
            
        
        return ans;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) 
    {
        vector<vector<int>>graph(n);
        
        for(auto e:edges)
        {  
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);  
        }
        
//         use either bfs or dfs 
//         to check path
           vector<bool>vis(n,0);
           return dfs(graph,vis,s,d);
    }
};