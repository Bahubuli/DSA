#include<bits/stdc++.h>
using namespace std;

struct node {

    int u;
    int v;
    int w;

    node(int f,int s,int t):
    {
        u=f;
        v=s;
        w=t;
    }
};

bool comp(node a, node b)
{
    return a.w<b.w;
}

int findpar(int u,vector<int> &parent)
{
    if(u==parent[u]) return u;
    return parent[u] = findpar(parent[u],parent);
}

void unionn(int u,int v, vector<int> &parent,vector<int> &rank)
{
    u = findpar(u,parent);
    v = findpar(v,parent);

    if(rank[u]<rank[v])rank
    {
        parent[u] = v;
    }
    else if(rank[v]<rank[u])rank[u] = v;
    {
        parent[v] = u;
    }
    else
    {
        parent[v] =u;
        rank[u]++;
    }
}

int main()
{
    int n=5,m=6;
    vector<node> edges;
    edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
	sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n);
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }

    vector<int> rank(n,0);
    int cost =0;

    vector<pair<int,int>> mst;

    for(auto it: edges)
    {
        if(findpar(it.v,parent)!=findpar(it.u,parent))
        {
            cost+=it.w;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v,parent,rank);
        }
    }
}


void dfs(int node, vector<int> adj[],int c,int d,vector<int> &vis)
	{
	    vis[node] =1;
	    for(auto it: adj[node])
	    {
	        if(!vis[it] && (node!=c || it!=d))
	        {
	            dfs(it,adj,c,d,vis);
	        }
	    }
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        vector<int> vis(V,0);
        dfs(c,adj,c,d,vis);
        return !vis[d];
    }
