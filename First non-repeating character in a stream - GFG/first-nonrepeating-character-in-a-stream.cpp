// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    
		    queue<char> q;
		    int mp[256] = {0};
		    
		    for(int i=0;i<s.size();i++)
		    {
		        char c = s[i];
		        mp[c]++;
		        if(mp[c]==1) q.push(c);
		        
		        while(q.size() && mp[q.front()]>1) q.pop();
		        
		        if(q.size()) s[i] = q.front();
		        else s[i] = '#';
		    }
		    return s;
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends