// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	long long int helper(int n, vector<long long int> &dp)
	{
	    if(n==1) return 2;
	    if(n==2) return 3;
	    
	    if(dp[n]!=-1) return dp[n];
	    long long int mod = 1e9+7;
	    return dp[n] = (helper(n-1,dp)%mod+helper(n-2,dp)%mod)%mod;
	}
	
	int TotalWays(int N)
	{
	    vector<long long int> dp(N+1,-1);
	    long long  int mod = 1e9+7;
	    long long int ans =  helper(N,dp);
	    return (ans*ans)%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends