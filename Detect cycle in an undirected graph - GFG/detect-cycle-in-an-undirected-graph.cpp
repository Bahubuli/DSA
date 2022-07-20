// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
   
   bool bfs(int node,vector<int> adj[],vector<bool>&vis)
   {
       queue<pair<int,int>>q;
       
       q.push({node,-1});
       
       while(q.size())
       {
           int s= q.size();
           
           while(s--)
           {
               auto f = q.front();
               q.pop();
               
               for(auto it: adj[f.first])
               {
                   if(!vis[it])
                   {
                       vis[it] = true;
                       q.push({it,f.first});
                   }
                   else
                   {
                       if(it!=f.second) return true;
                   }
               }
           }
       }
       
       return false;
   }
   
   
   
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,0);
        
        for(int node=0;node<V;node++)
        {
            if(!vis[node])
            {
                vis[node] = true;
                if(bfs(node,adj,vis)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends