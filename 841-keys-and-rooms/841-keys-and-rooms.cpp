class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms,int room,vector<bool>&vis)
    {
        vis[room] = true;
        for(auto it: rooms[room])
        {
            if(!vis[it])
            dfs(rooms,it,vis);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> vis(n,false);
        dfs(rooms,0,vis);
        for(int i=0;i<n;i++)
            if(!vis[i]) return false;
        
        return true;
    }
};