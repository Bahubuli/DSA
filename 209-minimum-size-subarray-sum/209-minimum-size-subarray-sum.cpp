class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int ans = INT_MAX;

    int i=0,j=0,n = nums.size(),sum=0;

    while(i<n && j<=n)
    {
        //cout<<i<<" "<<j<<endl;
        if(j <n && nums[j]==target) return 1;

        if(sum>=target)
        {
            
            ans = min(ans,j-i);
            sum-=nums[i];
            i++;
        }
        else
        {
            
            if(j<n) sum+= nums[j];
            j++;
        }
        

    }

     return ans==INT_MAX ? 0 : ans;
        
    }
};