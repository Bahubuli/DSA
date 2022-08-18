class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        int n = arr.size();
        map<int,int>mp;
        for(auto &x:arr) mp[x]++;
        
        priority_queue<int> pq;
        
        for(auto it:mp)
        {
            pq.push(it.second);
        }
        int ans = 0 ,c=0;
        while(pq.size() && c<n/2)
        {
            //cout<<pq.top()<<endl;
            c+=pq.top();
            ans++;
            pq.pop();
        }
        
        return ans;
        
    }
};