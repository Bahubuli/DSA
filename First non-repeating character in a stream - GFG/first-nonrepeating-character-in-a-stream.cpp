// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    
		    queue<int> q;
		    string ans = "";
		    int mp[26] = {0};
		    for(int i=0;i<s.size();i++)
		    {
		        mp[s[i]-'a']++;
		        
		        if(mp[s[i]-'a']==1) q.push(s[i]);
		        
		        while(q.size() && mp[q.front()-'a']!=1) q.pop();
		        
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