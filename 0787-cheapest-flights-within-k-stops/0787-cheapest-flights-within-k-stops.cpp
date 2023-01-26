class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<pair<int,int>> adj[n];
        
        for(auto f:flights)
        {
            adj[f[0]].push_back({f[1],f[2]});
        }
        
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> mheap;
        
        mheap.push({0,src,0});
        
        vector<int> steps(n+1,INT_MAX);
        
        while(mheap.size())
        {
            auto t = mheap.top();
            mheap.pop();
            int cost = t[0];
            int curr = t[1];
            int step = t[2];
            
            if(curr==dst)
                return cost;
            
            if(steps[curr]<step) continue;
                
            steps[curr] = step;
            
            if(step>k) continue;
            
            for(auto nxt : adj[curr])
            {
                mheap.push({cost+nxt.second,nxt.first,step+1});
            }
            
            
        }
        return -1;
        
    }
};