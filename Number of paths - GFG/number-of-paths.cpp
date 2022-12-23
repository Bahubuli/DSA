//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends


long long int helper(int i,int j,int m,int n)
{
    if(i==m || j==n) return 0;
    
    if(i==m-1 && j==n-1) return 1;
    
    return helper(i+1,j,m,n)+helper(i,j+1,m,n);
}

long long  numberOfPaths(int m, int n)
{
    return helper(0,0,m,n);
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