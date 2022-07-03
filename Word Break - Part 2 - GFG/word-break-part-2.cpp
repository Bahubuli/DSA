// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<string> ans;
    void helper(vector<string>&dict,string s,int n,string psf)
    {
        if(s.size()==0)
        {
            psf.erase(psf.begin()+psf.size()-1);
            ans.push_back(psf);
            return;
        }
        
        for(int i=0;i<s.size();i++)
        {
            string left = s.substr(0,i+1);
            
            if(find(dict.begin(),dict.end(),left)!=dict.end())
            {
                string right = s.substr(i+1);
                helper(dict,right,n,psf+left+" ");
            }
        }
        
        
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        string psf;
        helper(dict,s,n,psf);
        return ans;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends