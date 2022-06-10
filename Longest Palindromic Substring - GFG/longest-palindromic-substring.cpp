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
            j++;
            i--;
        }
        j--;
        i++;
        
        return j-i+1;
    }
    string longestPalindrome(string s)
    {
        int l=0,r=0,ans,n=s.size();
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++)
        {
            int res1 = expand(s,i,i+1);
            int res2 = expand(s,i,i);
            
            ans = max(res1,res2);
            if(r-l<ans)
            {
                l = i-(ans-1)/2;
                r = i+(ans)/2;
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