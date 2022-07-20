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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<vector<int>>ans;
        
        if(root==NULL)
            return ans;
        q.push(root);
        
        while(!q.empty())
        {
            int s =q.size();
            vector<int>level;
            for(int i=0;i<s;i++)
            {
                TreeNode *f = q.front();
                q.pop();
                level.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            ans.push_back(level);
        }
        
       return ans; 
    }
};