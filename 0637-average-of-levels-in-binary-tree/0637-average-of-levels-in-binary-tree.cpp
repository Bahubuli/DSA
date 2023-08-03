
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        
        if(root==NULL) return ans;
        
        queue<TreeNode *>q;
        q.push(root);
        
        while(q.size())
        {
            int n = q.size();
            double sum = 0;
            for(int i=0;i<n;i++)
            {
                TreeNode *f = q.front();
                q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                
                sum = sum+f->val;
            }
            ans.push_back(sum/n);
        }
        return ans;
    }
};