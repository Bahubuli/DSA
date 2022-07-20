// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    void dfs(vector<int> adj[],int s,int d,int &ans,vector<bool>&vis)
    {
        if(s==d)
        {
            ans++;
            return;
        }
        vis[s] = true;
        for(auto it: adj[s])
        if(!vis[it]) dfs(adj,it,d,ans,vis);
        
        vis[s] = false;
    }
    
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d)
	{
	    vector<int> adj[n];
	    vector<bool>vis(n,false);
	    int ans =0;
	    
	    for(auto e:edges)
	        adj[e[0]].push_back(e[1]);
	    
	    dfs(adj,s,d,ans,vis);
	    return ans;
	   
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends