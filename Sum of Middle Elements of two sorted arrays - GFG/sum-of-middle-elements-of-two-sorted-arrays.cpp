// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            
            int l = 0,h = n;
            while(l<=h)
            {
                int c1 = (l+h)/2;
                int c2 = (n+n+1)/2-c1;
                
                int l1 = (c1==0)? INT_MIN : ar1[c1-1];
                int l2 = (c2==0)? INT_MIN : ar2[c2-1];
                int r1 = (c1==n)? INT_MAX : ar1[c1];
                int r2 = (c2==n)? INT_MAX : ar2[c2];
                
                if(l1<=r2 && l2<=r1)
                {
                    return max(l1,l2)+min(r1,r2);
                }
                
                if(l1>r2) h = c1-1;
                if(l2>r1) l = c1+1;
            }
            return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends