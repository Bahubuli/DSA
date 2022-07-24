class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) 
    {

      
        int l = mat[0].size()-1;
        int d=0;
        
        while(d<mat.size() && l>=0)
        {
            if(mat[d][l]==x)
                return 1;
            else if(mat[d][l]>x)
            {
                l--;
            }
            else if(mat[d][l]<x)
            {
                d++;
            }
        }
        return false;
    }
};