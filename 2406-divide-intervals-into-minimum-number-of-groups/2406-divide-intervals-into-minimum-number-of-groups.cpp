class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int ans = 0;
        for(auto it:intervals)
        {
            if(pq.empty()) pq.push(it[1]);
            else
            {
                if(pq.top()<it[0]) pq.pop();
                pq.push(it[1]);
            }
            int s= pq.size();
            ans = max(ans,s);
        }
        return ans;
    }
};