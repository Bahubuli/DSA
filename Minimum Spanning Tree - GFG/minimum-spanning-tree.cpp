// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        bool mstpart[V] = {false};
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int ans =0;
        pq.push({0,0});
        
        while(pq.size())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            
            pq.pop();
            
            if(mstpart[node]) continue;
            mstpart[node] = true;
            ans+=dist;
            
            for(auto it: adj[node])
            {
                int v = it[0];
                int w = it[1];
                if(!mstpart[v]) pq.push({w,v});
            }
        }
        return ans;
        
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends