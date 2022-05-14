#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> adj[n];

    int a,b,wt;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }

    int parent[n];
    int key[n];
    bool mstSet[n];

    for(int i=0;i<n;i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    priority_queue<pair<int,int> , vector<pair<int,int>> greater<pair<int,int>>> pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0,0});
    for(int e=0;e<n-1;e++)
    {
      int u = pq.top().second;
        mstSet[u] = true;

        for(auto it : adj[u])
        {
            int v= it.first;
            int w = it.second;

            if(!mstSet[v] && w<key[v])
            {
                parent[v] = u;
                key[v] = w;
                pq.push({key[v],v};
            }

        }

        for(int i=1;i<n;i++)
        {
            cout<<parent[i]<<" -- "<<i<<endl;
        }
    }
}



    int spanningTree(int V, vector<vector<int>> adj[])
    {
        bool mstpart[V] = {false};
        int ans =0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(pq.size())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(mstpart[node]) continue;
            mstpart[node] = true;
            ans+=wt;

            for(auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if(!mstpart[v])
                 pq.push({w,v});

            }
        }
        return ans;
    }
