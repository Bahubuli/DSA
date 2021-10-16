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
        cout << curr->data << endl;
        for(int i=0;i<curr->children.size();i++)
            pendingnodes.push(curr->children[i]);
    }

}

int main()
{
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(12);
    // TreeNode<int> *node2 = new TreeNode<int>(13);

    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int> *root = takeinputlevelwise();
    printreelevelwise(root);
}
