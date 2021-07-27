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




Node * insertnoder(Node *head,int i,int data)
{
    if(head==NULL)
        return head;

    if(i==0)
    {
        Node *newnode = new Node(data);
        newnode->next = head;
        head = newnode;
        return head;
    }

        if (i == 1)
        {
            Node *newnode = new Node(data);
            newnode->next = head->next;
            head->next = newnode;
            return head;
    }
    Node *temp = insertnoder(head->next, i - 1, data);
    head->next = temp;
    return head;
}


void deletenode(Node * temp, int i)
        {
            while (i > 1 && temp != NULL)
            {
                i--;
                temp = temp->next;
            }
            Node *dNode = temp->next;
            temp->next = temp->next->next;
            delete dNode;
}

Node * deletenoder(Node * temp,int i)
{
    if(temp==NULL)
        return temp;
    if(i==0)
    {
        Node *temp2 = temp;
        temp = temp->next;
        delete temp2;
        return temp;
    }

        if (i == 1)
        {
            Node *temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            return temp;
    }
    Node *res = deletenoder(temp->next, i - 1);
    temp->next = res;
    return temp;
}

int findelement(Node *temp,int i,int x)
{
    if(temp==NULL)
        return -1;
    if(temp->data==x)
        return i;
    findelement(temp->next, i + 1, x);
}

int main()

{
        Node *head = takeInput();
        cout <<"\n"<< findelement(head, 0, 1) << endl;
        //print(head);
}
