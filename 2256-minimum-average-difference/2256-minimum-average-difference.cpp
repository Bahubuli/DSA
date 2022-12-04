class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        int n = nums.size();
        vector<long long int>left(n,0),right(n,0);
        
       long long  int p=0;
        
        for(int i=n-1;i>=0;i--)
        {
            right[i] = p;
            p=p+nums[i];
        }
        
        left[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]+nums[i];
        }
        long long int ans=INT_MAX,idx=0;
        for(int i=0;i<n-1;i++)
        {
           
            long long int md = abs(left[i]/(i+1) - right[i]/(n-i-1));
           // cout<<md<<endl;
            if(md<ans)
            {
                ans = md;
                idx = i;
            }
        }
        
       long long  int md = abs(left[n-1]/(n));
        if(md<ans)
        {
            ans = md;
            idx =n-1;
        }
        
        return idx;
        
    }
};