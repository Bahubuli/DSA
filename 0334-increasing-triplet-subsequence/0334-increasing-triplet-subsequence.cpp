class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        
        int mn = INT_MAX, md = INT_MAX, mx = INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mn)
                mn = nums[i];
            
            else if(nums[i]<=mx)
                mx = nums[i];
        
            else
                return true;  
              
        }
       
        return false;
    }
};