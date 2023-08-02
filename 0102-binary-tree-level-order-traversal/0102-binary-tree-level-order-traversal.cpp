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
        queue<TreeNode *>q;
        vector<vector<int>>ans;
        if(!root) return ans;
        q.push(root);
        
        while(q.size())
        {
            int s = q.size();
            vector<int>res;
            while(s--)
            {
                auto f =q.front();
                q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                res.push_back(f->val);
            }
            ans.push_back(res);
        }
        return ans;
    }
};