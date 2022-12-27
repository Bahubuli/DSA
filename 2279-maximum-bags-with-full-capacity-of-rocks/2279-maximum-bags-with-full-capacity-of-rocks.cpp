class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int d) 
    {
        int n = cap.size();
        for(int i=0;i<n;i++)
        {
            cap[i] = cap[i]-rocks[i];
        }
        
        sort(cap.begin(),cap.end());
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(cap[i]<=d)
            {
                ans++;
                d-=cap[i];
            }
            if(d==0)break;
        }
        return ans;
    }
};