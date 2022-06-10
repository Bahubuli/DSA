// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int expand(string s,int i,int j)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--;
            j++;
        }
        i++;
        j--;
        
        return (j-i+1);
    }
    
    string longestPalindrome(string s)
    {
        int n = s.size();
        reverse(s.begin(),s.end());
        int l=0,r=0,size=0;
        
        for(int i=0;i<n;i++)
        {
            int len1 = expand(s,i,i+1);
            int len2 = expand(s,i,i);
            
            size = max(len1,len2);
            
            if(r-l<size)
            {
                l = i - (size-1)/2;
                r = i+(size)/2;
            }
        }
        return s.substr(l,r-l+1);
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends