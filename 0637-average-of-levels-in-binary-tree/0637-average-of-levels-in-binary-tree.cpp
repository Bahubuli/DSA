
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size())
        {
            int s= q.size();
            double sum=0,count=0;
            while(s--)
            {
                auto f = q.front();
                q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                sum+=f->val;
                count++;
            }
            
            ans.push_back(sum/count);
        }
        return ans;
    }
};