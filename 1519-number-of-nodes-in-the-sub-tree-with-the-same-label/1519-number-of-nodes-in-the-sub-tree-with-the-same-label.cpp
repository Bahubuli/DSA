class Solution {
public:
    void createGraph(vector<vector<int>>&edges,vector<int>adj[])
{
    for(auto e:edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
}
    vector<int>dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans,string &s)
    {
        vector<int>mp(26,0);
        if(vis[node]) return mp;
        vis[node] = true;  
        for(auto it:adj[node])
        {
            vector<int>res = dfs(it,adj,vis,ans,s);
            for(int i=0;i<26;i++) mp[i]+= res[i];
        }
        mp[s[node]-'a']++;
        ans[node] = mp[s[node]-'a'];
        return mp;
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) 
    {
        vector<int>adj[n+1];
        createGraph(edges,adj);
        vector<int>ans(n,0),vis(n,0);
        dfs(0,adj,vis,ans,s);
        return ans;
        
        
    }
};