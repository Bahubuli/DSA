class Solution {
public:
    
    bool  bfs(vector<vector<int>>&graph,int s,int d)
    {
        int n = graph.size();
        queue<int>q;
        vector<bool>vis(n,0);
        
        q.push(s);
        
        while(q.size())
        {
            int curr = q.front();
            q.pop();
            
            if(curr==d) return true;
            
            
            for(int adj:graph[curr])
            {
                if(!vis[adj])
                {
                    q.push(adj);
                    vis[adj] = true;
                }
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) 
    {
        vector<vector<int>>graph(n);
        
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        return bfs(graph,s,d);
        
    }
};