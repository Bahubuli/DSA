class Solution {
public:
    int trap(vector<int>& height) 
    {
        int i=0,j=height.size()-1;
        int leftmx=0,rightmx=0,ans=0;
        while(i<j)
        {
            if(height[i]<height[j])
            {
                if(height[i]>leftmx) leftmx = height[i];
                else    ans+=leftmx-height[i];
                
                
                i++;
            }
            else
            {
                if(height[j]>rightmx) rightmx = height[j];
                else ans+= rightmx-height[j];
                
                j--;
            }
            
        }
        return ans;
        
    }
};