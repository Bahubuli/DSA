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
        vector<vector<int>>ans;
        
        if(root==NULL) return ans;
        
        queue<TreeNode *>q;
        q.push(root);
        
        bool flag= true;
        
        while(q.size())
        {
            int n = q.size();
            vector<int>level(n);
            for(int i=0;i<n;i++)
            {
                auto f = q.front();
                q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                
                if(flag)
                level[i] = f->val;
                else 
                    level[n-1-i] = f->val;
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }
};