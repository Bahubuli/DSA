// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        
        bitset<32> sa(a);
        bitset<32> sb(b);
      
        int ac = sa.count();
        int bc = sb.count();
        
        int d = abs(ac-bc);
        if(d==0) return a;
        
        else if(ac>bc)
        {
        while(d)
        {
            a = a&(a-1);
            d--;
        }
        }
        
        else 
        {
        while(d)
        {
            a = a| (a+1);
            d--;
        }
        }
        
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends