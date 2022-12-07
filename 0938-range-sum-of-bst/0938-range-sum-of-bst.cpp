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
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        
        if(root==NULL || (root->val>high && root->left==NULL)|| (root->val<low && root->right==NULL))
            return 0;
              
           int lr = rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
            
            if(root->val<=high && root->val>=low)
                return root->val+lr;
        
        return lr;
    }
};