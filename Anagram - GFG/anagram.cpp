// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        int mp1[26] = {0},mp2[26] = {0};
        
        for(auto c:a) mp1[c-'a']++;
        for(auto c:b) mp2[c-'a']++;
        
        for(int i=0;i<26;i++) if(mp1[i]!=mp2[i]) return false;
        return true;
        
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends