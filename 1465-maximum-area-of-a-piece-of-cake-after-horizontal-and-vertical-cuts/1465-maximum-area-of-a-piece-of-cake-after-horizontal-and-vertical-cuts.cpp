class Solution {
public:
    const long long int mod = 1000000007;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) 
    {
        int n = hc.size(),m= vc.size();
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
        
        vector<int> heights = {hc[0]};
        for(int i=1;i<n;i++)
            heights.push_back(hc[i]- hc[i-1]);
        
        heights.push_back(h-hc[n-1]);
        
        
        vector<int> lengths = {vc[0]};
        for(int i=1;i<m;i++)
        lengths.push_back(vc[i]-vc[i-1]);
        
        lengths.push_back(w-vc[m-1]);
        
        long long int a = *max_element(heights.begin(),heights.end());
        long long int b = *max_element(lengths.begin(),lengths.end());
        
        return (int)(a%mod*b%mod);
        
        
        
        
    }
};