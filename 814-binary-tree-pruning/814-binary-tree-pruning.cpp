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
    
   bool dfs(TreeNode *root)
    {
        if(!root) return NULL;
        
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        
        if(l==false) root->left = NULL;
        if(r==false) root->right = NULL;
        
        bool res = l+r+(root->val);
        
        return res;
        
    }
    
    TreeNode* pruneTree(TreeNode* root) 
    {
        auto ans = dfs(root);
        
        if(ans==0 && root->val==0) return NULL;
        
        return root;
    }
};