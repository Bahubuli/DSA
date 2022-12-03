class Solution {
public:
    string frequencySort(string s) 
    {
        map<char,int> mp;
        
        for(auto c:s) mp[c]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto it: mp) pq.push({it.second,it.first});
        
        string ans ="";
        
        while(pq.size())
        {
            ans+= string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return ans;
    }
};