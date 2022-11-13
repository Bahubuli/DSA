//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int>arr;
	    
	    int n = nums.size(),ans=0;
	    
	    for(int i=0;i<n;i++) arr.push_back(nums[i]);
	    sort(arr.begin(),arr.end());
	    
	    map<int,int> mp;
	    
	    for(int i=0;i<n;i++) mp[arr[i]] = i;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(i!=mp[nums[i]])
	        {
	            swap(nums[i],nums[mp[nums[i]]]);
	            ans++;
	            i--;
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends