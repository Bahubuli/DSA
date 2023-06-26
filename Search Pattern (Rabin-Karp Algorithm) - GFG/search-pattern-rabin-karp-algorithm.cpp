//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    
    
        vector <int> search(string pat, string txt)
        {
          
          vector<int>ans;
          int n =txt.size(),m = pat.size();
          int p =31, mod = 1e9+7;
          
          vector<long long>powers(n);
          powers[0] = 1;
          
        // calculating p0, p1 ,p2 ,p3 ,p4...  
          for(int i=1;i<n;i++)
          powers[i] = (powers[i-1]*p)%mod;
          
          
        // hash value of pat
        long long int pat_hash = 0;
        for(int i=0;i<pat.size();i++) 
          pat_hash = (pat_hash + (pat[i]-'a'+1)*powers[i])%mod;
        
        
        // calculating hash values
        vector<long long int>hash(n+1,0);
        for(int i=0;i<n;i++)
        hash[i+1] = (hash[i]+ (txt[i]-'a'+1)*powers[i])%mod;
        
        
        
        for(int i=0;i+m-1<n;i++)
        {
            long long curr = (hash[i+m]+mod-hash[i])%mod;
            if(curr==pat_hash*powers[i]%mod)
            ans.push_back(i+1);
        }

  if(ans.size()==0) ans.push_back(-1);
  return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends