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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        
        TreeNode *root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode *buildTree(vector<int>&preorder,int pst,int pnd,vector<int>&inorder,int ist,int ind,map<int,int>&mp)
    {
        if(pst>pnd  || ist>ind) return NULL;
        
        TreeNode *root = new TreeNode(preorder[pst]);
        int inroot = mp[root->val];
        int numleft = inroot-ist;
        
        root->left = buildTree(preorder,pst+1,pst+numleft,inorder,ist,inroot-1,mp);
        root->right = buildTree(preorder,pst+1+numleft,pnd,inorder,inroot+1,ind,mp);
        
        return root;
        
    }
};