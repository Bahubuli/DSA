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
    
    pair<TreeNode*,bool> dfs(TreeNode *root)
    {
        if(!root) return {NULL,false};
        
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        
        if(l.second==false) root->left = NULL;
        if(r.second==false) root->right = NULL;
        
        bool res = l.second+r.second+(root->val==1);
        
        return {root,res};
        
    }
    
    TreeNode* pruneTree(TreeNode* root) 
    {
        auto ans = dfs(root);
        
        if(ans.second==0 && root->val==0) return NULL;
        
        return root;
    }
};