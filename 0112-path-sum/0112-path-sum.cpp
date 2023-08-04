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
    bool hasPathSum(TreeNode* root, int t) {
        
        if(root==NULL) return false;
        
        if(root->left==NULL && root->right==NULL && root->val==t) return true;
        
        bool l = hasPathSum(root->left,t-root->val);
        bool r = hasPathSum(root->right,t-root->val);
        
        return l+r;
    }
};