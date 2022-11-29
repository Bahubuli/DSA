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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
       map<int,map<int,multiset<int>>>nodes;
        traverse(root,0,0,nodes);
        vector<vector<int>>ans;
        
        for(auto p: nodes)
        {
            vector<int> col;
            for(auto q: p.second)
            {
                for(auto x:q.second)
                    col.push_back(x);
            }
            ans.push_back(col);
        }
        return ans;
        
    }
    
    void traverse(TreeNode *root, int x,int y,map<int,map<int,multiset<int>>> &nodes)
    {
        if(root==NULL)
            return;
       
        if(root->left) traverse(root->left,x-1,y+1,nodes);
        if(root->right) traverse(root->right,x+1,y+1,nodes);
         nodes[x][y].insert(root->val);
    }
        
};