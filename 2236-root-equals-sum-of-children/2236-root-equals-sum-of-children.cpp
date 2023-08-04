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
    
    int helper(TreeNode *root,bool &ans)
    {
        if(root==NULL) return 0;
        
        if(root->left==NULL && root->right==NULL) return root->val;
        
        
        int l = helper(root->left,ans);
        int r = helper(root->right,ans);
        
        if(l+r!=root->val) ans= false;
        
        return root->val;
    }
    
    bool checkTree(TreeNode* root) 
    {
        bool ans = true;
        helper(root,ans);
        
        return ans;
        
        
    }
};