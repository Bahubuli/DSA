//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends


long long int helper(int i,int j,int m,int n,int dp[11][11])
{
    if(i==m || j==n) return 0;
    
    if(i==m-1 && j==n-1) return 1;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    return dp[i][j] = helper(i+1,j,m,n,dp)+helper(i,j+1,m,n,dp);
}

long long  numberOfPaths(int m, int n)
{
    int dp[11][11];
    memset(dp,-1,sizeof(dp));
    return helper(0,0,m,n,dp);
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends