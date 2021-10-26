#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode
{
    public:
        T data;
        vector<TreeNode<T> *> children;
        TreeNode(T data)
        {
            this->data = data;
        }
        // if we delcear this distructor we can directly
        // delete the tree with traversing postorder
        ~TreeNode()
        {
            for(int i=0;i<children.size();i++)
                delete children[i];
        }
};

TreeNode<int> *takeinput()
{
    int rootData;
    cout << "Enter Data " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter num of children of " << rootData << endl;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        TreeNode<int> *child = takeinput();
        root->children.push_back(child);
    }
    return root;
}

 TreeNode<int>* takeinputlevelwise()
 {
     int rootData;
     cout << "enter root data " << endl;
     cin >> rootData;
     TreeNode<int> *root = new TreeNode<int>(rootData);

     queue<TreeNode<int> *> pendingNodes;

     pendingNodes.push(root);
     while(pendingNodes.size()!=0)
     {
         TreeNode<int> *front = pendingNodes.front();
         pendingNodes.pop();
         cout << "enter number of childs of " << front->data << endl;
         int childcount;
         cin >> childcount;

         for(int i=0;i<childcount;i++)
         {
             int childdata;
             cout << "enter " << i << "th child of " << front->data << endl;
             cin >> childdata;
             TreeNode<int> *child = new TreeNode<int>(childdata);
             front->children.push_back(child);
             pendingNodes.push(child);
         }
    }
    return root;
 }



void printree(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " : ";

    for (int i = 0; i < root->children.size(); i++)
        cout << root->children[i]->data << " , ";
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
        printree(root->children[i]);
}

void printreelevelwise(TreeNode<int>* root)
{
    if(root == NULL)
        return;
    queue<TreeNode<int> *> pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty())
    {
        TreeNode<int> *curr = pendingnodes.front();
        pendingnodes.pop();
        cout << curr->data << " : ";
        for(int i=0;i<curr->children.size();i++)
            cout << curr->children[i]->data << " ";
        for(int i=0;i<curr->children.size();i++)
            pendingnodes.push(curr->children[i]);
        cout << endl;
    }

}

int countnodes(TreeNode<int>* root)
{
   if(root==NULL)
       return 0;
   queue<TreeNode<int> *> pendingnodes;
   pendingnodes.push(root);
   int count = 1;
   while(!pendingnodes.empty())
   {
       TreeNode<int> *curr = pendingnodes.front();
       pendingnodes.pop();

       for(int i=0;i<curr->children.size();i++)
       {
           pendingnodes.push(curr->children[i]);
           count++;
       }
   }
   return count;
}

 int countnodesr(TreeNode<int>* root)
 {
     if(root==NULL)
         return 0;

     int ans = 1;
     for(int i=0;i<root->children.size();i++)
     {
         ans += countnodesr(root->children[i]);
     }
     return ans;
 }

int heightoftree(TreeNode<int>* root)
{
    if(root==NULL)
        return 0;

    int maxh = 0;
    for(int i=0;i<root->children.size();i++)
    {
        maxh = max(heightoftree(root->children[i]),maxh);
    }
    return maxh+1;
}

void printatlevelk(TreeNode<int>*root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    for(int i=0;i<root->children.size();i++)
    {
        printatlevelk(root->children[i], k - 1);
    }
}

int leaf_nodes_count(TreeNode<int>*root)
{
    if(root==NULL)
        return 0;
    if(root->children.size()==0)
        return 1;
    int ln=0;
    for(int i=0;i<root->children.size();i++)
    {
        ln = ln + leaf_nodes_count(root->children[i]);
    }
    return ln;
}

void preorder(TreeNode<int> *root)
{
    cout << root->data << " ";
    for(int i=0;i<root->children.size();i++)
        preorder(root->children[i]);
}
void postorder(TreeNode<int> *root)
{
    for(int i=0;i<root->children.size();i++)
        postorder(root->children[i]);
    cout << root->data << " ";
}

void deleteTree(TreeNode<int>* root)
{
    //we can directly do delete root if we decleared distructor
    for(int i=0;i<root->children.size();i++)
        deleteTree(root->children[i]);
    delete root;
}

bool doesexist(TreeNode<int> *root,int x)
{
    if(root==NULL)
        return 0;
    if(root->data == x)
        return 1;
    int s = 0;
    for(int i=0;i<root->children.size();i++)
    {
        s = s + doesexist(root->children[i], x);
    }
    return s;
}
// naive approach
int maxsum(TreeNode<int> *root)
{
    if(root==NULL)
        return 0;
    if(root->children.size()==0)
        return root->data;
    int sum = root->data;

    for(int i=0;i<root->children.size();i++)
    {
        sum = sum + root->children[i]->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        sum = max(sum , maxsum(root->children[i]));
    }
    return sum;
}
TreeNode<int>* maxsumnode(TreeNode<int>*root,int mxsum)
{
    if(mxsum==0)
        mxsum = maxsum(root);

    int sum = root->data;
    for(int i=0;i<root->children.size();i++)
        sum = sum + root->children[i]->data;
    if(sum==mxsum)
        return root;
    TreeNode<int> *mxnode = NULL;
    for (int i = 0; i < root->children.size(); i++)
        {
            TreeNode<int> *childans = maxsumnode(root->children[i], mxsum);
            if(childans)
                mxnode = childans;
        }
        return mxnode;
}
// pairs hint
pair<TreeNode<int>*,int> maxsumn(TreeNode<int> *root)
{
    pair<TreeNode<int> *, int> ans;

    if (root == NULL)
    {
        ans.first = NULL;
        ans.second = 0;
        return ans;
    }

    if (root->children.size() == 0)
    {
        ans.first = root;
        ans.second = root->data;
        return ans;
    }

    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum = sum + root->children[i]->data;
    }
    ans.first = root;
    ans.second = sum;
    for (int i = 0; i < root->children.size(); i++)
    {
        pair<TreeNode<int> *, int> res = maxsumn(root->children[i]);
        if(res.second>ans.second)
            ans = res;
    }
    return ans;
}
// some conditions inside if can be skipped then we just need to call recursion few more times
bool structurally_identical(TreeNode<int>* root1,TreeNode<int>* root2)
{
    if(root1==root2 || (root1->data==root2->data && root1->children==root2->children))
        return true;

    if(root1->data!=root2->data || root1->children.size()!=root2->children.size())
        return false;
    bool ans = true;
    for(int i=0;i<root1->children.size();i++)
    {
        ans = min(ans, structurally_identical(root1->children[i], root2->children[i]));
    }
    return ans;
}
// first > element levelwise

int nextlargerlevelwise(TreeNode<int>*root,int x)
{
    if(root==NULL)
        return -1;
    if(root->data>x)
        return root->data;

    queue<TreeNode<int> *> q;
    q.push(root);
    int ans = -1;
    while(!q.empty())
    {
        TreeNode<int> *curr = q.front();
        for (int i = 0; i < curr->children.size(); i++)
        {
            q.push(curr->children[i]);
        }
        for (int i = 0; i < curr->children.size(); i++)
        {
            if(curr->children[i]->data>x)
                return curr->children[i]->data;
        }

    q.pop();
    }
    return ans;
}

// element which is just > x from all elements of tree
int secondlargest(TreeNode<int>* root,int x)
{
    int ans = INT_MAX;
    if(root->data>x)
        ans = root->data;
    for(int i=0;i<root->children.size();i++)
    {
        int res = secondlargest(root->children[i], x);
        ans = min(ans, res);
    }
    return ans;
}


//1 3 12 22 34 2 55 66 2 77 58 0 0 0 0 1 57 0
int main()
{
    TreeNode<int> *root = takeinputlevelwise();
    replacewithdepth(root, 0);
    printreelevelwise(root);
}
