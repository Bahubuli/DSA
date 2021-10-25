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

void inorder(BtNode<int> *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int diameter(BtNode<int>* root)
{
    if(root==NULL)
        return 0;

    int res1 = height(root->left) + height(root->right);
    int res2 = diameter(root->left);
    int res3 = diameter(root->right);

    return max(res1, max(res2, res3));
}
/*
time complexity = n*h
in case of balanced bt = nlogn
in case of flat bt = n*n
*/

pair<int ,int > heightdiameter(BtNode<int>* root)
{
    if(root==NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> lres = heightdiameter(root->left);
    pair<int, int> rres = heightdiameter(root->right);

    int ld = lres.second;
    int lh = lres.first;
    int rd = rres.second;
    int rh = rres.first;

    int h = 1 + max(lh, rh);
    int d = max(lh + rh, max(ld, rd));

    pair<int, int> p;
    p.first = h;
    p.second = d;
    return p;
}
// time complexity o(n) because we are using pairs

pair<int,int> minmax(BtNode<int>* root)
{
    if(root==NULL)
    {
        pair<int, int> base;
        base.first = INT_MAX;
        base.second = INT_MIN;
        return base;
    }

    pair<int, int> res1 = minmax(root->left);
    pair<int, int> res2 = minmax(root->right);

    int lmin = res1.first;
    int lmax = res1.second;
    int rmin = res2.first;
    int rmax = res2.second;

    pair<int, int> ans;

    ans.first = min(min(lmin, rmin), root->data);
    ans.second = max(max(lmax, rmax), root->data);

    return ans;
}

int sumnodes(BtNode<int>* root)
{
    if(root==NULL)
        return 0;
    return root->data + sumnodes(root->left) + sumnodes(root->right);
}

bool isbalanced(BtNode<int>* root)
{
    if(root==NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);

    if(max(lh,rh)-min(lh,rh)>1)
    return false;
    bool res1= true;
    bool res2 = isbalanced(root->left);
    bool res3 = isbalanced(root->right);

    return min(min(res2, res3), res1);
}

pair<bool,int> isbalancedheight(BtNode<int>* root)
{
    if(root==NULL)
    {
        pair<bool, int> base;
        base.first = true;
        base.second = 0;
        return base;
    }
    pair<bool, int> res1;
    res1.first = true;
    pair<bool, int> res2 = isbalancedheight(root->left);
    pair<bool, int> res3 = isbalancedheight(root->right);

    if(max(res2.second,res3.second)-min(res2.second,res3.second)>1)
        res1.first = false;
    res1.second = 1 + max(res2.second, res3.second);

    pair<bool, int> ans;
    ans.first = min(min(res2.first, res3.first), res1.first);
    ans.second = 1 + max(res2.second, res3.second);

    return ans;
}


void levelorderasitis(BtNode<int>* root)
{
    if(root==NULL)
        return;
    queue<BtNode<int> *> rest;
    rest.push(root);
    rest.push(NULL);

    while(!rest.empty())
    {
        BtNode<int> *front = rest.front();
        rest.pop();
        if(front!=NULL)
        {
            cout << front->data<<" ";
            if (front->left != NULL)
                rest.push(front->left);
            if (front->right != NULL)
                rest.push(front->right);
        }
        if(front==NULL && rest.size()>0)
        {
            rest.push(NULL);
            cout << endl;
        }
    }
}

//better time complexity
void removeleafs(BtNode<int>* root)
{
    if(root==NULL)
        return;

    if(root->left!=NULL)
    if(root->left->left==NULL && root->left->right==NULL)
        root->left = NULL;

    if(root->right!=NULL)
    if (root->right->left == NULL && root->right->right == NULL)
        root->right = NULL;

    removeleafs(root->left);
    removeleafs(root->right);
}

void removeleaf(BtNode<int> *root)
{
    if(root==NULL)
        return;
    if(height(root->left) ==1)
        root->left = NULL;
    if(height(root->right) ==1)
        root->right = NULL;

    removeleaf(root->left);
    removeleaf(root->right);
}

void printsinglechild(BtNode<int>* root)
{
    if(root==NULL || (root->left ==NULL && root->right==NULL))
        return;

    if(root->left==NULL && root->right!=NULL)
        cout << root->right->data << endl;

    if (root->right == NULL && root->left != NULL)
        cout << root->left->data << endl;

    printsinglechild(root->left);
    printsinglechild(root->right);
}

//  1 2 3 4 5 6 7 -1 -1  -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BtNode<int> *root = takeinputlw();
    printsinglechild(root);
}
