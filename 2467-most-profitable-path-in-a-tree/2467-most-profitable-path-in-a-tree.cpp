class Solution {
public:
    
    bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&path)
    {
        if(node==0)
        {
            path.push_back(node);
            return true;
        }
        
        if(vis[node]) return false;
        
        vis[node] = true;
        
        for(auto it:adj[node])
        {
            int res = dfs(it,adj,vis,path);
            if(res) 
            {
                path.push_back(node);
                return true;
            }
        }
        
        return false;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
    {
        int n = amount.size(),ans=INT_MIN;
        vector<int>adj[n+1],vis(n+1,0),path;
        
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(bob,adj,vis,path);
        
        
        
        amount[bob] = 0;
        path.pop_back();
        
        
        queue<pair<int,int>>q;
        q.push({0,amount[0]});
        
        fill(vis.begin(),vis.end(),0);
       
        while(q.size())
        {
            int bobloc = -1;
            if(path.size())
            {
                bobloc = path.back();
                path.pop_back();
            }
            
            int s = q.size();
            //cout<<s<<endl;
            while(s--)
            {
                int node = q.front().first;
                int val = q.front().second;
                q.pop();
                
                if(vis[node]) continue;
                
                vis[node] = true;
                
                if(adj[node].size()==1 && node!=0) ans = max(ans,val);
                
                for(auto it:adj[node])
                {
                    if(vis[it]) continue;
                    
                    if(it==bobloc) q.push({it,val+(amount[it])/2});
                    else q.push({it,val+amount[it]});
                }
            }
            
            if(bobloc!=-1) amount[bobloc] = 0;
        }
        
        return ans;
        
    }
};
















