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
    
    TreeNode* helper(TreeNode* root)
    {
      
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL)
            return root;
       
         TreeNode *ltail = helper(root->left);
        TreeNode *rtail = helper(root->right);
       
       
        
       if(rtail==NULL) rtail = ltail;
        
       if(root->left)
        {    
         ltail->right = (root->right)?root->right:NULL;
         root->right=root->left;
         root->left=NULL;
        }

        return rtail;
    }
    
    void flatten(TreeNode* root) 
    {
        TreeNode *d = helper(root);  
    }
};