class Solution {
public:
    
    int gcd(int a,int b)
    {
        return a==0 ? b:gcd(b%a,a);
    }
    
    int getGCD(vector<int>&arr)
    {
        int gcd_all = arr[0];
        for(int i=1;i<size(arr);i++)
        {
            gcd_all = gcd(arr[i],gcd_all);
            if(gcd_all==1) return 1;
        }
        return gcd_all;
    }
    
    int minOperations(vector<int>& nums, vector<int>& numsd) 
    {
        int gcd_all = getGCD(numsd);
        sort(begin(nums),end(nums));
        
        int ans = 0;
        for(auto x:nums)
        {
            if(gcd_all%x==0) return ans;
            ans++;
        }
        return -1;
        
    }
};