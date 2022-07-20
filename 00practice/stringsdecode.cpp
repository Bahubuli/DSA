   #include<bits/stdc++.h>
   using namespace std;

   string decodeString(string s)
    {
        stack<int>nst;
        stack<string>st;
        string ans = "";
        string stringtobepushed = "";
        string numtobepushed = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]-'0'>=0 && s[i]-'0'<=9)
            {
                numtobepushed = numtobepushed + s[i];

            }
            else if(s[i]!='[')
            {
                numtobepushed="";
            }

            if(s[i]=='[')
            {
                if(numtobepushed!="")
                nst.push(stoi(numtobepushed));
            }

            if(s[i]>='a' && s[i]<='z')
            {
                stringtobepushed = stringtobepushed+s[i];
            }
            else if(s[i]==']')
            {
                string res = "";
                if(stringtobepushed!="")
                st.push(stringtobepushed);
                string sttp = st.top();
                st.pop();

                if(!nst.empty())
                {
                    int t = nst.top();
                    nst.pop();
                    while(t--)
                    {
                        res=res+sttp;
                    }
                    if(!nst.empty())
                    {
                        st.push(res);
                    }
                    else
                    {
                        ans=res+ans;
                    }
                }

            }
            else
            {
                stringtobepushed="";
            }

        }
        if(!st.empty())
        {
            ans=st.top()+ans;
        }

        return ans;

    }
int main()
{
    string s = "3[a]2[bc]";
    cout<<decodeString(s)<<endl;
    cout<<"done"<<endl;
}



    int maxpsum(TreeNode *root,int &maxi)
    {
        if(root==NULL)
            return 0;
        int lp = max(0,maxpsum(root->left,maxi));
        int rp = max(0,maxpsum(root->right,maxi));

        maxi = max(maxi,lp+rp+root->val);
        return max(lp,rp) + root->val;
    }

    int maxPathSum(TreeNode* root)
    {
        int maxi = INT_MIN;
        maxpsum(root,maxi);
        return maxi;

    }
 bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(p==NULL && q==NULL)
            return true;
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
            return false;

        bool cr = (p->val==q->val);


        bool lr = isSameTree(p->left,q->left);
        bool rr = isSameTree(p->right,q->right);

        return min(cr,min(lr,rr));
    }
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p) return !q;
        if(!q) return !p;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }


  vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        queue<TreeNode*> q;

        vector<vector<int>>ans;

        if(root==NULL)
            return ans;
        q.push(root);
        int iseven=0;
        while(!q.empty())
        {
            vector<int>res;
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                res.push_back(q.front()->val);

                TreeNode *f = q.front();
                q.pop();
                cout<<f->val<<" ";

                    if(f->right) q.push(f->right);
                    if(f->left) q.push(f->left);

            }
            cout<<endl;
            iseven++;
            if(iseven%2==1) reverse(res.begin(),res.end());
            ans.push_back(res);
        }

        return ans;
    }


  vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        queue<TreeNode*> q;

        vector<vector<int>>ans;

        if(root==NULL)
            return ans;
        q.push(root);
        bool flag=0;
        int idx;
        while(!q.empty())
        {

            int n = q.size();
            vector<int>res(n);
            for(int i=0;i<n;i++)
            {
                idx = flag ? i : n-i-1;
                TreeNode *f = q.front();
                q.pop();
                res[idx]=f->val;

                    if(f->right) q.push(f->right);
                    if(f->left) q.push(f->left);

            }

            flag=!flag;
            ans.push_back(res);
        }

        return ans;
    }


void addleftb(Node *root,vector<int>&ans)
{
    if(root==NULL)
    return;
    if(root->left==NULL && root->right==NULL)
    return;

    ans.push_back(root->data);
    if(root->left) addleftb(root->left,ans);
    else addleftb(root->right,ans);

}

void addrightb(Node *root,vector<int>&ans)
{
    if(root==NULL)
    return;
   if(root->left==NULL && root->right==NULL)
   return;
   if(root->right) addrightb(root->right,ans);
   else addrightb(root->left,ans);
   ans.push_back(root->data);

}
void addleaves(Node *root,vector<int>&ans)
{
    if(root==NULL) return;

   if(root->left==NULL && root->right==NULL)
   {
       ans.push_back(root->data);
       return;
   }

   addleaves(root->left,ans);
   addleaves(root->right,ans);

}

    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL)
        return ans;
        if(root->left!=NULL || root->right!=NULL)
        ans.push_back(root->data);

        addleftb(root->left,ans);
        addleaves(root,ans);
        addrightb(root->right,ans);

        return ans;

    }

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
        return diameter;
    }

    void vot(TreeNode *root,vector<vector<int>> &ans,int i)
    {
        if(root==NULL)
            return;
        if(i<ans.size())
        ans[i].push_back(root->val);
        vot(root->left,ans,i-1);
        vot(root->right,ans,i+1);

    }

    int ld(TreeNode *root,int i,int &mx)
    {
        if(root==NULL)
            return 0;

        int l = ld(root->left,i+1,mx);
        int r = ld(root->right,i-1,mx);

        mx = max(mx,max(l,r));
        return i;
    }


    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        int d = diameterOfBinaryTree(root);
        //cout<<d<<endl;

        int i=0;
        int mx=0;
        if(root->left)
        {i = ld(root->left,0,mx)+1;
        mx=mx+1;

        }

         vector<vector<int>>ans(d+1);
        //cout<<mx<<endl;
        vot(root,ans,mx);
        vector<vector<int>>ans2;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i].size()>0)
                ans2.push_back(ans[i]);
        }
        return ans2;
    }


map<int, map<int, multiset<int>>> m;
void dfs(TreeNode* r, int x, int y) {
  if (r != nullptr) {
    m[x][y].insert(r->val);
    dfs(r->left, x - 1, y + 1);
    dfs(r->right, x + 1, y + 1);
  }
}
vector<vector<int>> verticalTraversal(TreeNode* r, vector<vector<int>> res = {}) {
  dfs(r, 0, 0);
  for (auto itx = m.begin(); itx != m.end(); ++itx) {
      res.push_back(vector<int>());
      for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity) {
          res.back().insert(end(res.back()), begin(ity->second), end(ity->second));
      }
  }
  return res;
}


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
                col.insert(col.end(),q.second.begin(),q.second.end());
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
