// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    
    
  
    int shortestDistance(int n, int m, vector<vector<int>> mat, int x, int y) 
    {
        if(mat[0][0] ==0 || mat[x][y]==0) return -1;
        queue<pair<int,pair<int,int>>>q;
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {-1,1,0,0};
        int i,j,d;
        bool ans= false;
        q.push({0,{0,0}});
        mat[0][0] = 0;
        
        while(q.size())
        {
            auto f = q.front();
            q.pop();
            d = f.first;
            i = f.second.first;
            j = f.second.second;
            
            if(i==x && j==y)
            {
                ans = true;
                break;
            }
            
            for(int idx=0;idx<4;idx++)
            {
                int xn = i+dx[idx];
                int yn = j+dy[idx];
                
                if(xn>=0 && xn<n && yn>=0 && yn<m && mat[xn][yn])
                    {
                        q.push({d+1,{xn,yn}});
                        mat[xn][yn] = 0;
                    }
            }
            
        }
       return ans ? d: -1;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends