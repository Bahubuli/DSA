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
    bool isValidBST(TreeNode* root) 
    {
        return helper(root,LONG_MIN,LONG_MAX);        
    }
    
    bool helper(TreeNode *root,long long int  l,long long  r)
    {
        if(root==NULL) return true;
        if(root->val>=r || root->val<=l) return false;
        
        return helper(root->left,l,root->val) && helper(root->right,root->val,r);
    }
    
};