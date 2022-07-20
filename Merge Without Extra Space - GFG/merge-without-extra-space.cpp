// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            long long gap = (n+m)/2 + (n+m)%2;
            while(gap>=1)
            {
                long long i=0,j=gap;
                while(j<n+m)
                {
                  
                    long long *x, *y;
                    
                    if(i>=n) x = &arr2[i++ - n];
                    else  x = &arr1[i++];
                    
                    if(j>=n) y = &arr2[j++ - n];
                    else  y = &arr1[j++];
                    
                    if(*x>*y) swap(*x,*y);
                    
                }
                 if(gap==1) break;
                gap = (gap/2) + (gap%2);
            }
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends