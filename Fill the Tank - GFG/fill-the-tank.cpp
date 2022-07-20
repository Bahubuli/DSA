// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    
    long long dfs(vector<int> adj[],int node,int par,int *cap)
    {
        long long req = 0, child = 0;
        
        for(auto anode: adj[node])
        {
            if(anode!=par)
            {
            child++;
            long long childreq = dfs(adj,anode,node,cap);
            if(childreq==-1) return childreq;
            
            req = max(req,childreq);
            }
        }
        
        if(child*req+ cap[node] > 1e18) return -1;
        
        return child*req + cap[node-1];
    }
    
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap)
    {
        vector<int> adj[N+1];;
        for(auto e:Edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        bool pos = 1;
        return dfs(adj,S,-1,Cap);
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends