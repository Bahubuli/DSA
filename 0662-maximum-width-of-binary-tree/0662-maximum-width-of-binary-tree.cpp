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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root) return 0;
        
        int ans = 1;
        queue<pair<TreeNode *,long long>>q;
        q.push({root,0});
        
        while(q.size())
        {
            int s= q.size();
            int start = q.front().second;
            int end = q.back().second;
            ans = max(ans,end-start+1);
            
            while(s--)
            {
                auto node = q.front().first;
                int idx = q.front().second-start;
                q.pop();
                
                if(node->left) q.push({node->left,(long long)2*idx+1});
                if(node->right) q.push({node->right,(long long)2*idx+2});
            }
        }
        return ans;
    }
};