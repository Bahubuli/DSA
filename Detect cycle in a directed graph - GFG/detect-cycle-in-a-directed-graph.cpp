// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    bool dfs(int node,vector<int> adj[],vector<bool> &vis,vector<bool> &dfsvis)
    {
        if(vis[node]) return true;
        
        vis[node] = true;
        dfsvis[node] = true;
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,dfsvis)) return true;
            }
            else if(dfsvis[it]) return true;
        }
        
        dfsvis[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<bool> vis(V,0),dfsvis(V,0);
        
        for(int node=0;node<V;node++)
        {
            if(!vis[node])
            {
                if(dfs(node,adj,vis,dfsvis)) return true;
            }
        }
        
        return false;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends