#include<bits/stdc++.h>
using namespace std;

 void sortColors(vector<int>& nums,int s,int e,int lv,int rv)
    {
        if(lv>=rv || s>=e)
        return;

        int l=s,c=s,h =e ;
        int count =0;
        while(c<=h)
        {
                count++;
            if(nums[c]==lv)
            {
                int temp = nums[c];
                nums[c] = nums[l];
                nums[l]=temp;
                l++;
                c++;


            }

            else if(nums[c]>lv && nums[c]<rv)
            {
                c++;
            }
            else if(nums[c]==rv)
            {
                int temp = nums[c];
                nums[c]=nums[h];
                nums[h]=temp;
                h--;
            }

        }
        sortColors(nums,l,h,lv+1,rv-1);

    }

int main()
{
  vector<int>arr = {0,0,0,1,1,1,0,0,0};
  sortColors(arr,0,arr.size()-1,0,1);

 for(auto x:arr)
  cout<<x<<" ";

}
