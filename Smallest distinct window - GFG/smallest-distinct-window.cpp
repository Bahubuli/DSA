// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        vector<int>hash(256,-1);
        int uc=0;
        
        for(auto &c:s)
        {
            if(hash[c]==-1)
            {
                hash[c] = 0;
                uc++;
            }
        }
        
        int i=0,j=0,n = s.size();
        int c=0,ans = INT_MAX;
        
        while(i<n && j<=n)
        {
            if(c<uc)
            {
                if(hash[s[j]]==0) c++;
                hash[s[j]]++;
                j++;
                // cout<<c<<endl;
            }
            else
            {
                ans = min(ans,j-i);
                
                // cout<<i<<" "<<j<<endl;
                hash[s[i]]--;
                if(hash[s[i]]==0) c--;
                i++;
            }
        }
        
        if(c==uc) ans = min(ans,j-i);
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends