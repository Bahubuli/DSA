class Solution {
public:
    
    bool canbeshipped(vector<int>&nums,int d, int cap)
    {
        int i=0,n=nums.size(), t=0;
        int b=0;
        while(i<n)
        {
            if(nums[i]>cap) return false;
            if(b+nums[i]<cap)
            {
                b+=nums[i];
                i++;
            }
            else if(b+nums[i]==cap)
            {
                b=0;
                t++;
                i++;
            }
            else
            {
                t++;
                b=0;
            }
          
        }
        //cout<<t<<" "<<d<<endl;
        if(b>0) t++;
        if(t<=d) return true;
        else 
            return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int l=1, h = 500000;
        int ans =0;
       
        while(l<=h)
        {
            int mid = l+ (h-l)/2;
            if(canbeshipped(weights,days,mid))
            {
                
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
            
           
        }
        return ans;
    }
};