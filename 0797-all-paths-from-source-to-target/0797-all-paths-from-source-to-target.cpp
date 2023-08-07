class Solution {
public:
    
    void dfs(vector<vector<int>>&graph,int v,vector<int>path,vector<vector<int>>&paths)
    {
        path.push_back(v);
        int n  = graph.size();
        
        if(v==n-1)
            paths.push_back(path);
        
        
        for(auto adj:graph[v])
            dfs(graph,adj,path,paths);
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>>paths;
        vector<int>path;
        
        dfs(graph,0,path,paths);
        
        return paths;
        
    }
};