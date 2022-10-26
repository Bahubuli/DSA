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

    key[0] = 0;
    parent[0] = -1;

    for(int e=0;e<n-1;e++)
    {
        int mini = INT_MAX,u;

        for(int v = 0;v<n;v++)
        {
            if(!mstSet[v] && key[v]<mini)
            {
                u = v;
                mini = key[v];
            }
        }
        mstSet[u] = true;

        for(auto it : adj[u])
        {
            int v= it.first;
            int w = it.second;

            if(!mstSet[v] && w<key[v])
            {
                parent[v] = u;
                key[v] = w;
            }

        }

        for(int i=1;i<n;i++)
        {
            cout<<parent[i]<<" -- "<<i<<endl;
        }
    }
}
