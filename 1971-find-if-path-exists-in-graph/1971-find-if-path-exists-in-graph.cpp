class Solution {
public:
    
    bool haspath(vector<vector<int>>&graph,vector<bool>&vis,int s,int d)
    {
      
        queue<int>q;
        q.push(s);
        vis[s] = true;
        while(q.size())
        {
            int curr = q.front();
            q.pop();
            
            if(curr==d) return true;
            
            for(auto it:graph[curr])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        
        return false;
            
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