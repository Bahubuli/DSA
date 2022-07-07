// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    bool brainGame(vector<int>nums) 
    {
        int dp[1005] = {0};
        dp[1] = dp[2] = 0;
        
        for(int i=3;i<=1000;i++)
        {
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    dp[i] = max(dp[i],1+max(dp[i/j],dp[j]));
                }
            }
        }
        
        
        int ans =0;
        for(auto x:nums) ans = dp[x]^ans;
        
        return ans>0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends