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

//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    TreeNode<int> *root = takeinputlevelwise();
    cout<<doesexist(root,10);
}
