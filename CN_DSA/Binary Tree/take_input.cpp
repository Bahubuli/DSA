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


int main()
{
    BtNode<int>*root = takeinput();
    printbtree(root);
}
