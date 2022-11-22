class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>&source) 
    {
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        
        int n = maze.size(),m=maze[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<vector<int>>q;
        
        q.push({source[0],source[1],0});
        
        while(q.size())
        {
            int s = q.size();
            
            while(s--)
            {
                auto f = q.front();
                q.pop();
                int x = f[0],y=f[1],d=f[2];
                //cout<<x<<" "<<y<<" "<<vis[x][y]<<endl;
                
                if(vis[x][y]) continue; 
                vis[x][y] = true;
                
                for(int i=0;i<4;i++)
                {
                    int xi = x+dx[i];
                    int yi = y+dy[i];
                    
                    if(xi>=0 && yi>=0 && xi<n && yi<m && !vis[xi][yi] && maze[xi][yi]=='.')
                         if(xi==0 || yi==0 || xi==n-1 || yi==m-1) return d+1;
                         else q.push({xi,yi,d+1});
                }
            }
        }
        return -1;
        
    }
};