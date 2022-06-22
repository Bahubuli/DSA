// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    set<char> st;
    
    int i=0,j=-1,ans=0,n=s.size();
    
    while(j<n)
    {
        j++;
        if(st.find(s[j])!=st.end())
        {
            while(i<j && st.find(s[j])!=st.end()) 
            {
              
                st.erase(s[i]);
                i++;
            }
            
        }  
      st.insert(s[j]);
        //cout<<i<<" "<<j<<endl;
        ans = max(min(j,n-1)-i+1,ans);
    }
    return ans;
}