struct compare{
    public:
       bool operator()(const pair<string,int> &a,const pair<string,int>&b)
    {
        return a.second<b.second || (a.second==b.second && a.first>b.first);
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare>  pq;
        
        map<string,int> mp;
        for(auto w:words) mp[w]++;
        
        for(auto it: mp) pq.push(it);
        vector<string>ans;
        
        while(k--)
        {
           auto top = pq.top();
           pq.pop();
            ans.push_back(top.first);
        }   
        return ans;
        
    }
};