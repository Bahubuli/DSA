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
    
    int maxpsum(TreeNode *root,int &maxi)
    {
        if(root==NULL)
            return 0;
        int lp = max(0,maxpsum(root->left,maxi));
        int rp = max(0,maxpsum(root->right,maxi));
        
        maxi = max(maxi,lp+rp+root->val);
        return max(lp,rp) + root->val;
    }
    
    int maxPathSum(TreeNode* root) 
    {
        int maxi = INT_MIN;
        maxpsum(root,maxi);
        return maxi;
        
    }
};