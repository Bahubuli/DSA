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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        bool flag= true;
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size())
        {
            int s = q.size();
            vector<int>level(s,0);
            for(int i=0;i<s;i++)
            {
                auto f= q.front();
                q.pop();
                if(flag)
                level[i] = f->val;
                else 
                    level[s-1-i] = f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                
            }
            flag  = !flag;
            ans.push_back(level);
        }
        return ans;
    }
};