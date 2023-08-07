class Solution {
public:
    
    void dfs(vector<vector<int>>&graph,vector<int>path,vector<vector<int>>&paths,int v)
    {
       
        int n = graph.size();
         path.push_back(v);
        
        if(v==n-1)
            paths.push_back(path);

        
        for(int adj:graph[v])
            dfs(graph,path,paths,adj);
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        
        vector<vector<int>>paths;
        vector<int>path;
        
        dfs(graph,path,paths,0);
        
        return paths;
    }
};