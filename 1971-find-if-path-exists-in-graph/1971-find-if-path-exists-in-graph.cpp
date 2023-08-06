class Solution {
public:
    
    bool haspath(vector<vector<int>>&graph,vector<bool>&vis,int s,int d)
    {
        if(vis[s]) return false;
        
        if(s==d) return true;
        
        vis[s] = 1;
        bool ans = false;
        
        for(auto it:graph[s])
            ans+= haspath(graph,vis,it,d);
        
        return ans;
            
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
       
        vector<vector<int>>graph(n+1);
        
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<bool>vis(n+1,0);
        return haspath(graph,vis,s,d);
    }
};