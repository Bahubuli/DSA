#include <iostream>
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
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *insertnode(Node *head, int i, int data)
{
    Node *newnode = new Node(data);
    if (i == 0)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        int count = 0;
        Node *temp = head;
        while (count < i - 1 && temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        if (temp != NULL)
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

Node *insertnoder(Node *head, int i, int data)
{
    if (head == NULL)
        return head;

    if (i == 0)
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

void deletenode(Node *temp, int i)
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

Node *deletenoder(Node *temp, int i)
{
    if (temp == NULL)
        return temp;
    if (i == 0)
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

Node *ht[2];
Node ** reversell(Node *head)
{
    if(head->next==NULL)
    {
        ht[0] = head;
        ht[1] = head;
        return ht;
    }
        Node *temp = head;
        Node *curr = temp->next;
        Node *prev = temp;
        Node *nxt = curr->next;

        while (nxt != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
    }
    curr->next = prev;
    temp->next = NULL;
    head = curr;

    ht[0] = head;
    ht[1] = temp;
    //cout << ht[0]->data << " " <<ht[0]->next->data<<" "<< ht[1]->data << endl;
    return ht;
}



Node *kreverse(Node *head,int k)
{
    
    Node *h1 = head, *t1 = head,*h2,*t2;
    Node *prev = NULL;
    int count = 0;
    while(true)
    {
        count++;
        for (int i = 1; (i < k && t1->next != NULL); i++)
        {
            t1 = t1->next;
        }
        //cout << t1->data<< " d" << endl;

        t2 = t1->next;
        t1->next = NULL;
        //cout << "h1->data " << h1->data << endl;
        Node **ht = reversell(h1);
        if(prev==NULL)
        {
            head = ht[0];
            prev = ht[1];
        }
        else
        {
            prev->next = ht[0];
            prev = ht[1];
        }

        t1 = t2;
        h1 = t2;
        if(h1==NULL)
            return head;
    }
    if (count == 6)
        return head;

}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif

    Node *head = takeInput();

    //cout << findmindnode(head)->data << endl;
    head = kreverse(head, 10);
    print(head);
}
