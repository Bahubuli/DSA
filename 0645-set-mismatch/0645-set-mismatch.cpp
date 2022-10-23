class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n = nums.size(),xr =0,dup,extra;
        
        for(int i=1;i<=n;i++)
        {
            xr = xr^nums[i-1];
            xr = xr^i;
        }
        // xor of missing + extra;
        
        int set_bit_no = xr & ~(xr-1);
        
        int x =0 , y=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] & set_bit_no) x = x^nums[i];
            else y = y^nums[i];
            
            if( (i+1) & set_bit_no) x = x^(i+1);
            else y = y^(i+1);
        }
        
    for(int i=0;i<n;i++)
    {
        if(nums[i]==x) return {x,y};
    }
        
        return {y,x};
        
    }
};