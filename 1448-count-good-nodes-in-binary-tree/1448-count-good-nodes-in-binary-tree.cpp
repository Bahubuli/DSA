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
    
    void helper(TreeNode *root,int &ans,int mx)
    {
        if(!root) return;
        if(root->val>=mx) ans++;
        
        helper(root->left,ans,max(mx,root->val));
        helper(root->right,ans,max(mx,root->val));
        
    }
    
    int goodNodes(TreeNode* root) 
    {
        int ans = 0;
        helper(root,ans,INT_MIN);
        return ans;
        
    }
};