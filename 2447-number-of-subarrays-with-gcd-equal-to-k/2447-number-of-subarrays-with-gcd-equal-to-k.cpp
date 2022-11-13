class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            int gcd =nums[i] ;
            for(int j=i;j<nums.size();j++)
            {
                

                gcd = __gcd(nums[j],gcd);
                if(gcd==k) ans++;
                //cout<<gcd<<" "<<j<<endl;
               
            }
        }
        return ans;
        
    }
};