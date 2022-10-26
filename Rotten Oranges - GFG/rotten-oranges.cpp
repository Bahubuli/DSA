//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size(),ans=0;
        queue<pair<int,int>>q;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2)
                    q.push({i,j});
                    
        
        while(q.size())
        {
            int s= q.size();
            ans++;
            while(s--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int idx=0;idx<4;idx++)
                {
                    int x = i+dx[idx];
                    int y = j+dy[idx];
                    
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
                    {
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
                
            }
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)
                    return -1;
                
        return ans-1;
            
        
        
        
       
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends