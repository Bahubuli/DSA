class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2) q.push({i,j});
        
        int ans = 0;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        while(q.size())
        {
            int s = q.size();
            int c = 0; 
            while(s--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx = x+dx[i],ny=y+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1)
                    {
                        c = 1;
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            ans+=c;
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1) return -1;
        
        return ans;
    }
};