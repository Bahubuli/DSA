#include<bits/stdc++.h>
using namespace std;


 vector<int> getAverages(vector<int>& nums, int k)
    {
        if(k==0)
            return nums;
        if(k>nums.size())
            return {-1};

        int n = nums.size();

       vector<int>ans(n);
        int j=0;
        long long int  sum=0;
        int l=k;

        int w = 2*k;

        for(int i=0;i<=w;i++)
        {
            sum = sum+nums[i];
        }
         j=0;
        int i=k;
        cout<<sum<<endl;
        l=2*k;
        while(l<n)
        {
            ans[i] = sum/(2*k+1);
            i++;
            l++;

            sum = sum-nums[j]+nums[l];
            j++;
        }

        for(int i=0;i<k;i++)
        {
            ans[i]=-1;
        }

        for(int j=n-1;j>n-1-k;j--)
        {
            ans[j]=-1;
        }

        return ans;

    }

int main()
{
    vector<int> arr = {40527, 53696, 10730, 66491, 62141, 83909, 78635, 18560};
    int k =2;

    vector<int> ans = getAverages(arr, k);

    for(auto x:ans)
        cout << x << endl;
}
