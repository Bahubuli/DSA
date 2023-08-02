
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(q.size())
        {
            vector<int>level;
            int s = q.size();
            
            while(s--)
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