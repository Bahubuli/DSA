// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(int node, int par,vector<int> adj[],vector<bool>&vis)
    {
        vis[node] = true;
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                 if(dfs(it,node,adj,vis)) return true;
            }
           
            
            else if(it!=par) return true; 
        }
        
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> vis(V,0);
        
        for(int node=0;node<V;node++)
        {
            if(!vis[node])
            if(dfs(node,-1,adj,vis)) return true;
            
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