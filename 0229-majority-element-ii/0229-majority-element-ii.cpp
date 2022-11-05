class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int c1=0,c2=0,num1=INT_MIN,num2=INT_MIN,n=nums.size();
        for(auto x:nums)
        {
            if(x==num1) c1++;
            else if(x==num2) c2++;
            else if(c1==0)
            {
                c1++;
                num1=x;
            }
            else if(c2==0)
            {
                c2++;
                num2=x;
            }
            else
            {
                c2--;
                c1--;
            }
            
        }
       
        c1=0,c2=0;
        for(auto x:nums)
        {
            if(x==num1) c1++;
            if(x==num2) c2++;
        }
        
        vector<int>ans;
        
        if(c1>n/3) ans.push_back(num1);
        if(c2>n/3) ans.push_back(num2);
        
        return ans;
    }
};