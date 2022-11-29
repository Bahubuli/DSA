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
    
    void dfs(TreeNode *root,long long int idx,int d,vector<long long int> &left,int &ans)
    {
         if(!root) return;
         if(d>=left.size()) left.push_back(idx); 
         
        ans = max((long long)ans,idx-left[d]+1);
        
        if(root->left) dfs(root->left,2*(idx-left[d]),d+1,left,ans);
        if(root->right) dfs(root->right,2*(idx-left[d])+1,d+1,left,ans);
    }
    
    int widthOfBinaryTree(TreeNode* root) 
    {
        int ans=1;
        vector<long long int>left;
        dfs(root,1,0,left,ans);
        return ans;  
    }
};