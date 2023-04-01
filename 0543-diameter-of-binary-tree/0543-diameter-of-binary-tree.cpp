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
    
    int helper(TreeNode *root,int &ans)
    {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int l = helper(root->left,ans);
        int r = helper(root->right,ans);
        
        ans = max(ans,l+r);
        return max(l,r)+1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root)
    {
        int ans = 0;
         helper(root,ans);
        
        return ans;
        
        
    }
};