class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int l=0,r=height.size()-1,ans=0;
        
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                ans = max(ans,min(height[l],height[r])*(r-l));
                l++;
            }
            else
            {
                 ans = max(ans,min(height[l],height[r])*(r-l));
                r--;
            }
        }
        return ans;
    }
};