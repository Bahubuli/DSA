
   int height(TreeNode *root,int &d)
    {
        if(root==NULL)
            return 0;

        int l=height(root->left,d);
        int r=height(root->right,d);

        d=max(d,l+r);
        return 1+max(l,r);

    }

    int diameterOfBinaryTree(TreeNode* root)
    {
       int diameter=0;
        int h = height(root,diameter);
        cout<<h<<endl;
        return diameter;
    }
