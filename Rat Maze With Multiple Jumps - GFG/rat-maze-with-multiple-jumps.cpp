// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<vector<int>> ShortestDistance(vector<vector<int>>&mat)
	{
	    int n = mat.size(), m = mat[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    if( helper(mat,ans,0,0)) return ans;
	    return {{-1}};
	   
	}
	
	bool isvalid(int i,int j,vector<vector<int>> mat)
	{
	    int n = mat.size(),m = mat[0].size();
	    if(i>=n  || j>=m || mat[i][j]==0) return false;
	    return true;
	}
	
	bool helper(vector<vector<int>> &mat,vector<vector<int>> &ans,int i,int j)
	{
	    int n = mat.size(),m = mat[0].size();
	    if(i==n-1 && j==m-1)
	    {
	        ans[i][j]=1;
	        return true;
	    }
	    
	    if(isvalid(i,j,mat))
	    {
	        ans[i][j] = 1;
	        for(int s =1;s<=mat[i][j];s++)
	        {
	            if(helper(mat,ans,i,j+s)) return true;
	            if(helper(mat,ans,i+s,j)) return true;
	        }
	        ans[i][j]=0;
	    }
	    return false;
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends