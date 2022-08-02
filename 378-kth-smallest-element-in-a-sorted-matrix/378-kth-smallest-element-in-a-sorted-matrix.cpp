class Solution {
public:
    int n;
    int kthSmallest(vector<vector<int>>& mat, int k) {
        n = mat.size();
        
        int l = mat[0][0],r=mat[n-1][n-1],ans;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(count(mat,mid)>=k)
            {
                ans = mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
    
    int count(vector<vector<int>> &mat,int mid)
    {
        int ans =0,c=n-1;
        
        for(int r=0;r<n;r++)
        {
            while(c>=0 && mat[r][c]>mid ) c--;
            
            ans+=(c+1);
        }
        return ans;
    }
};