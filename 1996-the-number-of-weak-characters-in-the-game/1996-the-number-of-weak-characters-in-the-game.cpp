class Solution {
public:
    static bool comp(vector<int>&a , vector<int>&b)
    {
        if(a[0]!=b[0]) return a[0]>b[0];
        else return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& nums) 
    {
        sort(nums.begin(),nums.end(),comp);
       //reverse(nums.begin(),nums.end());
        int ans = 0;
       
        int mx =INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
                if(nums[i][1]<mx) ans++;
                else mx = nums[i][1];
            
        }
        return ans;
    }
};