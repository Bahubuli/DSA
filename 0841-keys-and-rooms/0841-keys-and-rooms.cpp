class Solution {
public:
    
    void dfs(vector<vector<int>>&rooms,int node,vector<int>&vis)
    {
        if(vis[node]) return;
        
        vis[node] = true;
        
        for(auto adjnode:rooms[node])
            if(!vis[adjnode]) dfs(rooms,adjnode,vis);
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<int>vis(n,false);
        
        dfs(rooms,0,vis);
        
        for(auto x:vis) if(!x) return false;
        
        return true;
        
    }
};