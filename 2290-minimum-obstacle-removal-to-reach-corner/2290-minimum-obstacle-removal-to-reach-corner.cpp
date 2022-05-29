class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    
     int minimumObstacles(vector<vector<int>>& grid) 
     {
         int n=grid.size() , m = grid[0].size();
         vector<vector<int>> dp(n,vector<int> (m,1e5+1));
         
         priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,
         greater<tuple<int,int,int>>> pq;
         
         pq.push({grid[0][0],0,0});
         
         while(pq.size())
         {
             auto [c,i,j] = pq.top();
             pq.pop();
             
             if(i==n-1 && j==m-1)
             {
                 return c+grid[i][j];
             }
             
             for(int idx=0;idx<4;idx++)
             {
                 int x = dx[idx]+i;
                 int y = dy[idx]+j;
                 
                 if(x<0 || y<0 || x>=n || y>=m) continue;
                 
                 if(dp[x][y]>grid[x][y]+c)
                 {
                     dp[x][y] = grid[x][y]+c;
                     pq.push({grid[x][y]+c,x,y});
                 }
             }
             
         }
         return -1;
         
         
     }
        
    
};