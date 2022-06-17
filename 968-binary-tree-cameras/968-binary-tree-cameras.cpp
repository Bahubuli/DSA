/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int installcameras(TreeNode *root, int &ans,int p)
    {
        if(!root) return 1;
        int lres = installcameras(root->left,ans,1);
        int rres = installcameras(root->right,ans,1);
        
        if(lres ==0 || rres ==0)
        {
            ans++;
            return 2;
        }
        
        if(lres ==2 || rres ==2)
        {
            return 1;
        }
        
        if(lres==1 && rres==1)
        {
            if(p==0) ans++;
            return 0;
        }
        return 0;
    }
    
    
    int minCameraCover(TreeNode* root) 
    {
        int ans =0;
        
        installcameras(root,ans,0);
        
        return ans;
    }
};