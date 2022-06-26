// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int helper(int *nums, int n,int k)
    {
        map<int,int> mp;
        int count=0,i=0;
        
        for(int j=0;j<n;j++)
        {
            mp[nums[j]]++;
            while(i<=j && mp.size()>k)
            {
                if(mp[nums[i]]==1) mp.erase(nums[i]);
                else mp[nums[i]]--;
                
                i++;
            }
            count+= (j-i+1);
        }
        return count;
    }
    
    int countDistinctSubarray(int arr[],int n)
    {
        set<int>st;
        for(int i=0;i<n;i++) st.insert(arr[i]);
        int k = st.size();
        return helper(arr,n,k)-helper(arr,n,k-1);
    }
    
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends