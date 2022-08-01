class Solution {
public:
    
    void dfs(int i,int dist,vector<int>&e, vector<int>&dp)
    {
        while(i!=-1 && dp[i]==-1)
        {
            dp[i] = dist++;
            i  = e[i];
        }
    }
    
    int closestMeetingNode(vector<int>&e ,int node1 ,int node2)
    {
        int ans = -1, mind = INT_MAX;
        vector<int>dp1(e.size(),-1), dp2(e.size(),-1);
        
        dfs(node1,0,e,dp1);
        dfs(node2,0,e,dp2);
        
        for(int i=0;i<e.size();i++)
        {
            if(min(dp1[i],dp2[i])>=0 && max(dp1[i],dp2[i])<mind)
            {
                mind = max(dp1[i],dp2[i]);
                ans = i;
                
            }
        }
        
        return ans;
        
    }
   
};