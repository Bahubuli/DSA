class Solution {
public:
    void allpaths(vector<vector<int>>&graph,int node,vector<int>path,vector<vector<int>>&paths)
    {
        int n = graph.size();
        if(node==n-1) paths.push_back(path);
        
        for(auto it:graph[node])
        {
            path.push_back(it);
            allpaths(graph,it,path,paths);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>>ans;
        vector<int>path;
        path.push_back(0);
        allpaths(graph,0,path,ans);
        
        return ans;
        
    }
};