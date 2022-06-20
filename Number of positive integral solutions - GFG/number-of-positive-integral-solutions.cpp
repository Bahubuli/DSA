// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    
   
    long posIntSol(string s)
    {
        int n = s.size();
        int c=0,k=0;
        
        for(int i=0;i<n;i++)
        {
            int j =i;
            while(s[j]>='a' && s[j]<='z') j++;
            c++;
            
            if(s[j]=='=')
            {
                k = stoi(s.substr(j+1));
                break;
            }
            i=j;
        }
        
        if(k<c) return 0;
        
        long ans = 1;
        for(int i=1;i<c;i++) ans *= (k-i);
        for(int i=1;i<c;i++) ans /= (c-i);
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends