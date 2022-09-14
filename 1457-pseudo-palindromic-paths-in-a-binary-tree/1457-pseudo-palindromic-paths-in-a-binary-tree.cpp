class Solution {
public:
    
    
    void dfs(TreeNode *root,vector<int>&mp,int &ans)
    {
        if(!root) return;
        
        mp[root->val]++;
        if(!root->left && !root->right)
        {
            int odd=0;
            for(int i=1;i<=9;i++)
            {
                //cout<<it.first<<" "<<it.second<<endl;
                if(mp[i]%2) odd++;
            }
            //cout<<odd<<endl;
            if(odd<=1) ans++;
            mp[root->val]--;
            return;
        }
        
        
        dfs(root->left,mp,ans);
        dfs(root->right,mp,ans);
        mp[root->val]--;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) 
    {
       vector<int>mp(10,0);
        int ans = 0;
        dfs(root,mp,ans);
        return ans;
        
    }
};