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
    
    void dfs(TreeNode *root,int x,int y,map<int,map<int,multiset<int>>>&mp)
    {
        if(!root) return;
        
        if(root->left) dfs(root->left,x-1,y+1,mp);
        if(root->right) dfs(root->right,x+1,y+1,mp);
        
        mp[x][y].insert(root->val);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int,map<int,multiset<int>>>mp;
        dfs(root,0,0,mp);
        
        vector<vector<int>>ans;
        
        for(auto x:mp)
        {
            vector<int>col;
            
            for(auto y:x.second)
                for(auto num:y.second)
                    col.push_back(num);
            
            ans.push_back(col);
                
        }
        return ans;
        
    }
};