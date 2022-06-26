// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        int i=0,j=0,ans=0;
        map<int,int> mp;
        set<int> st;
        
        for(int i=0;i<n;i++) st.insert(arr[i]);
        
        int k = st.size();
        
        for(int j=0;j<n;j++)
        {
            mp[arr[j]]++;
            
            while(mp.size()==k && i<=j)
            {
                ans+=(n-j);
                mp[arr[i]]--;
                
                if(mp[arr[i]]==0) mp.erase(arr[i]);
                i++;
            }
        }
        return ans;
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