#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BtNode
{
    public:
    T data;
    BtNode* left;
    BtNode* right;

    BtNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BtNode()
    {
        delete left;
        delete right;
    }
};

void printbtree(BtNode<int>* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    if(root->left)
    cout<<"L : "<<root->left->data<<" ";

    if(root->right)
    cout<<"R : "<<root->right->data<<" ";
    cout<<endl;
    printbtree(root->left);
    printbtree(root->right);
}

void printtreelw(BtNode<int>* root)
{
    queue<BtNode<int>*> rest;
    rest.push(root);

    while(rest.size()!=0)
    {
        BtNode<int>* front = rest.front();
        cout<<front->data<<" ";
        rest.pop();
        if(front->left!=NULL)
        {
        rest.push(front->left);
        cout<<"L : " <<front->left->data<<" ";
        }

        if(front->right!=NULL)
        {
        rest.push(front->right);
        cout<<"R : "<<front->right->data<<" ";
        }
        cout<<endl;
    }
}

BtNode<int> *takeinput()
{
    int rootData;
    cout<<"enter data "<<endl;
    cin>>rootData;
    if(rootData == -1)
    return NULL;

    BtNode<int> * newn = new BtNode<int>(rootData);
    BtNode<int>* leftc = takeinput();
    BtNode<int>* rightc = takeinput();

    newn->left = leftc;
    newn->right = rightc;

    return newn;

}
BtNode<int> *takeinputlw()
{
    int Data;
    cout<<" enter data ";
    cin>>Data;
    BtNode<int>* root = new BtNode<int>(Data);

    queue<BtNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty())
    {
        BtNode<int> *front = pendingnodes.front();
        pendingnodes.pop();

        cout<<"enter left child of "<<front->data<<endl;
        int leftc;
        cin>>leftc;

        if(leftc!= -1)
        {
            BtNode<int>* lnode = new BtNode<int>(leftc);
            front->left = lnode;
            pendingnodes.push(lnode);
        }
        cout<<"enter right child of "<<front->data<<endl;
        int rightc;
        cin>>rightc;

        if(rightc!= -1)
        {
            BtNode<int>* rnode = new BtNode<int>(rightc);
            front->right = rnode;
            pendingnodes.push(rnode);
        }

    }
    return root;
}

int countnodes(BtNode<int>* root)
{
    if(root==NULL)
        return 0;

    return 1 + countnodes(root->left) + countnodes(root->right);
}

int height(BtNode<int>* root)
{
    if(root==NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

void mirrorbt(BtNode<int>* root)
{
    if(root==NULL)
        return;
    BtNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorbt(root->left);
    mirrorbt(root->right);
}

void postorder(BtNode<int>* root)
{
    if(root==NULL)
        return;
    postorder(root->left);

    postorder(root->right);
    cout << root->data << " ";
}
//  1 2 3 4 5 6 7 -1 -1  -1 -1 8 9 -1 -1 -1 -1 -1 -1


int main()
{
    BtNode<int>*root = takeinputlw();

    postorder(root);
}
