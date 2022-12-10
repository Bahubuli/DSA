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
    
     int mod = 1e9+7;
    
    long long int sum(TreeNode *root)
    {
        if(!root) return 0;
        return (root->val+sum(root->left)+sum(root->right));
    }
    
    long long int dfs(TreeNode *root,long long int &s, long long int &ans)
    {
        if(!root) return 0;
        
         long long int l = dfs(root->left,s,ans);
         long long int r = dfs(root->right,s,ans);
        
        ans = max(ans,((s-l)*l));
        ans = max(ans,((s-r)*r));
      
        
        return (l+r+root->val);
    }
    
    int maxProduct(TreeNode* root) 
    {
        long long int ans = 0;
        long long s = sum(root);
        
        dfs(root,s,ans);
        return ans%mod;
        
    }
};