// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
        long long gap = (n + m) / 2 + (n + m) % 2;
    while(gap >= 1){
        long long it1 = 0, it2 = gap;
        while(it2 < n + m){
            long long *cur1, *cur2;
            
            if(it1 >= n)    cur1 = &arr2[it1++ - n];
            else    cur1 = &arr1[it1++];

            if(it2 >= n)    cur2 = &arr2[it2++ - n];
            else    cur2 = &arr1[it2++];
    
            if(*cur1 > *cur2)   swap(*cur1, *cur2);
        }
        if(gap == 1)    break;
        gap = (gap / 2) + (gap % 2);
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