#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data!=-1)
    {
        Node *newnode= new Node(data);
        if(head==NULL)
        {
            head = newnode;
            tail = newnode;
        }
            else
            {
                tail->next = newnode;
                tail = tail->next;
        }
        cin >> data;

    }
    return head;
}


void print(Node * head)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* insertnode( Node *head,int i,int data)\
{
    Node *newnode = new Node(data);
    if(i==0)
    {
        newnode->next = head;
        head = newnode;

    }
    else
    {




        int count = 0;
        Node *temp = head;
        while (count < i - 1 && temp!=NULL)
        {
            temp = temp->next;
            count++;
        }
        if(temp!=NULL)
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else
        {
            cout << "out of the range index" << endl;

        }


    }

        return head;
}









void deletenode(Node *temp,int i)
{
    while(i>1 && temp!=NULL)
    {
        i--;
        temp = temp->next;
    }
    Node *dNode = temp->next;
    temp->next = temp->next->next;
    delete dNode;
}
int findnode(Node *temp,int x,int count)
{
    if(temp==NULL)
    {
        return -1;
    }
    if(temp->data==x)
    {
        return count;
    }
    findnode(temp->next, x, count + 1);
}

Node *reverserecur(Node *prev,Node *curr)
{
    if(curr==NULL)
        return prev;

        Node *next = curr->next;
        curr->next = prev;
        Node *nhead = reverserecur(curr, next);
        return nhead;
}





int main()

{
        Node *head = takeInput();
        head = reverserecur(NULL, head);

        print(head);
 }
