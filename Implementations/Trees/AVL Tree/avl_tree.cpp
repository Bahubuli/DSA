#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node *left;
    int data;
    Node *right;
    int height;

    Node(int x)
    {
        data = x;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

class AVL
{
    public:
    Node *root;

    AVL()
    {
        root = NULL;
    }

    int height(Node *node)
    {
       if(!node) return 0;
        return max(height(node->left),height(node->right))+1;
    }

    int bfactor(Node *node)
    {
        if(!node) return 0;
        return (height(node->left)-height(node->right));
    }
    Node *next(Node *node)
    {
        while(node && node->right) node = node->right;
        return node;
    }
    Node *prev(Node *node)
    {
        while(node && node->left) node = node->left;
        return node;
    }

    Node *LL(Node *node)
    {
        Node *node_left = node->left;
        Node *node_left_right = node_left->right;

        node_left->right = node;
        node->left = node_left_right;

        node->height = height(node);
        node_left->height = height(node_left);

        if(root==node)
            root = node_left;

        return node_left;
    }

    Node *RR(Node *node)
    {
        Node *node_right = node->right;
        Node *node_right_left = node_right->left;

        node_right->left = node;
        node->right = node_right_left;

        node->height = height(node);
        node_right->height = height(node_right);

        if(root==node)
        root = node_right;

        return node_right;
    }

    Node *RL(Node *node)
    {
       node->right = RR(node->right);
       return LL(node);
    }

    Node *LR(Node *node)
    {
       node->left = LL(node->left);
       return RR(node);
    }

    Node *insert(Node *node,int data)
    {
        Node *t;
        if(node==NULL) return (new Node(data));

        if(data<node->data) node->left = insert(node->left,data);
        else if(data>node->data) node->right = insert(node->right,data);

        node->height = height(node);

        int bf = bfactor(node),lbf = bfactor(node->left),rbf = bfactor(root->right);

        if(bf==2 && lbf==1) return LL(node);
        if(bf==2 && lbf==-1) return LR(node);
        if(bf==-2 && rbf==-1) return RR(node);
        if(bf==-2 && rbf==1) return RL(node);

        return node;
    }

    void inorder(Node *node)
    {
        if(node)
        {
            inorder(node->left);
            cout<<node->data<<" , ";
            inorder(node->right);
        }
    }
    void inorder()
    {
        inorder(root);
    }
    Node *deleteNode(Node *node,int data)
    {
        if(node==NULL) return NULL;

        if(!node->left && !node->right)
        {
            if(node==root) root = NULL;
            delete node;
            return NULL;
        }

        if(data<node->data) node->left = deleteNode(node->left,data);
        else if(data>node->data) node->right = deleteNode(node->right,data);
        else
        {
            Node *p;
            if(height(node->left) > height(node->right))
            {
                p = next(node->left);
                node->data =  p->data;
                node->left = deleteNode(node->left,p->data);
            }
            else
            {
                p = prev(node->right);
                node->data = p->data;
                node->right = deleteNode(node->right,p->data);
            }
        }

        node->height = height(node);
        int bf = bfactor(node),lbf = bfactor(node->left),rbf = bfactor(root->right);

        if(bf==2 && (lbf==1 || lbf==0)) return LL(node);
        if(bf==-2 && (rbf==-1 || rbf==0)) return RR(node);
        if(bf==2 && lbf==-1) return LR(node);
        if(bf==-2 && rbf==1) return RL(node);

        return node;

    }


};

int main()
{
    AVL tree;
    vector<int> a = {54,44,86};

    for(auto x:a)
    {
        tree.root = tree.insert(tree.root,x);
    }
    tree.inorder();
    tree.deleteNode(tree.root,54);
    cout<<endl;
    tree.inorder();
    cout<<endl;
    tree.deleteNode(tree.root,44);
    tree.inorder();
    tree.deleteNode(tree.root,86);

    tree.inorder();

}
