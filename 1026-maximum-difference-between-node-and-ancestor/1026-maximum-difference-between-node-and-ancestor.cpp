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
    
    pair<int,int> helper(TreeNode *root,int &ans)
    {
        if(root==NULL)
            return {0,0};
       if(!root->left && !root->right)
       {
           pair<int,int> base;
           base = {root->val,root->val};
           return base;
       }
        int lcmax=0,rcmax=0;
        pair<int,int>lres;
        pair<int,int>rres;
        
        if(root->left) lres = helper(root->left,ans);
        if(root->right)  rres = helper(root->right,ans);
        
        if(root->left) lcmax = max(abs(root->val-lres.first),abs(root->val-lres.second));
        if(root->right) rcmax = max(abs(rres.first-root->val),abs(rres.second-root->val));
        
        ans = max(ans,max(lcmax,rcmax));
        
        //cout<<ans<<" "<<endl;
        if(!root->left) return {min(root->val,rres.first),max(root->val,rres.second)};
        if(!root->right) return  {min(root->val,lres.first),max(root->val,lres.second)};
        
        
        pair<int,int>res = {min(min(lres.first,lres.second),min(rres.first,rres.second))
                            ,max(max(rres.first,rres.second),max(lres.first,lres.second))};
                                                                                
        
     res = {min(res.first,root->val),max(res.second,root->val)};
        return res;
    }
    
    int maxAncestorDiff(TreeNode* root) 
    {
        int ans=INT_MIN;
        
        helper(root,ans);
        return ans;
        
    }
};