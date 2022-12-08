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
    stack<int> st;
    int n1=0,n2=0;
    void rdfs(TreeNode *root)
    {
        if(!root) return;
        rdfs(root->right);
        if(!root->left && !root->right)
        {
            st.push(root->val);
            n1++;
        }
        rdfs(root->left);
    }
     void ldfs(TreeNode *root)
    {
        if(!root) return;
        ldfs(root->left);
        if(!root->left && !root->right)
        {
            if(st.size() && st.top()==root->val)
            st.pop();
            n2++;
        }
        ldfs(root->right);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        rdfs(root1);
        ldfs(root2);
        
        //cout<<st.size()<<endl;
        return st.size()==0 && n1==n2;
    }
};