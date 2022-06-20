// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
       int s1=0,s2=0;
        
        for(int i=0;i<n;i++) s1+=A[i];
        for(int i=0;i<m;i++) s2+=B[i];
        
        sort(A,A+n);
        sort(B,B+m);
        int i=0,j=0;
        while(i<n && j<m)
        {
          int v1 = s1 - A[i] + B[j];
       int v2 = s2 - B[j] + A[i];
            
            if(v1==v2) return 1;
            
            else if(v1>v2) i++;
            else j++;
        }
        return -1;
        
    //     int sum1=0,sum2=0;
    //   for(int i=0;i<n;i++) sum1 += A[i];
    //   for(int i=0;i<m;i++) sum2 += B[i];
    //   sort(A,A+n);
    //   sort(B,B+m);
    //   int i=0,j=0;
    //   while(i<n && j<m){
    //       int v1 = sum1-A[i]+B[j];
    //       int v2 = sum2+A[i]-B[j];
    //       if(v1==v2) return 1;
    //       else if(v1>v2) i++;
    //       else j++;
    //   }
    //   return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends