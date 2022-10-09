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

class BSTIterator
{
    public:
    stack<TreeNode *>st;
    bool reverse;
    
    BSTIterator(TreeNode *root,bool isreverse)
    {
        reverse = isreverse;
        pushall(root);
    }
    
    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        if(reverse) pushall(temp->left);
        else pushall(temp->right);
        return temp->val;
    }
    
    void pushall(TreeNode *node)
    {
        if(!node) return;
        
        while(node)
        {
            st.push(node);
            if(reverse) node = node ->right;
            else node = node ->left;
        }
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) 
    {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i = l.next();
        int j = r.next();
        
        while(i<j)
        {
            if(i+j==k) return 1;
            else if(i+j<k) i = l.next();
            else j = r.next();
        }
        return false;
        
    }
};