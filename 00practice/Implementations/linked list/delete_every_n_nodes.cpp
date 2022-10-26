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

int findelement(Node *temp, int i, int x)
{
    if (temp == NULL)
        return -1;
    if (temp->data == x)
        return i;
    findelement(temp->next, i + 1, x);
}

void eliminatedups(Node *temp)
{

    while (temp->next != NULL)
    {

        Node *temp2 = NULL;

        if (temp->data == temp->next->data)
        {
            temp2 = temp->next;
            temp->next = temp->next->next;

            delete temp2;
        }
        else
        {
            temp = temp->next;
        }
    }
}

void printreverse(Node *temp)
{
    if (temp == NULL)
        return;
    printreverse(temp->next);
    cout << temp->data << " ";
}

Node *reversell(Node *head)
{
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
    return head;
}

Node *findmindnode(Node *head)
{
    Node *p1 = head;
    Node *p2 = head;

    while (p2 != NULL && p2->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}


/*
void *deleteeverynnodes(Node *head, int n, int m)
{
    Node *temp = head;
    while (temp != NULL )
    {

        int cn = n;
        int cm = m;
        if(n==1 && temp!=head)
            temp = temp->next;
        else
        {
            while (cn >1  && temp != NULL)
            {
                cn--;
                temp = temp->next;
            }
        }
        cout << temp->data << "... ";
        while (cm > 0 and temp != NULL and temp->next !=NULL)
        {

            Node *dn = temp->next;
            temp->next = temp->next->next;
            delete dn;
            cm--;
        }
        if (n == 1 && temp == head)
            temp = temp->next;
    }
    return;
}
*/
void skipmdeleten(struct Node *head, int M, int N)
{
  Node *curr = head, *mthnode, *nthnode, *t;

    // The main loop that traverses through the whole list
    while (curr != NULL)
    {

        // Skip M nodes
        if (M != 0)
        {
            M--;
            if (M == 0)
                mthnode = curr;
        }
        else
        {
            N--;
            if (N == 0)
            {
                nthnode = curr;
                break;
            }
        }
        curr = curr->next;

    }
    if (curr == NULL)
        return;
    mthnode->next = nthnode->next;
    nthnode->next = NULL;
}


void skipMdeleteN(Node *head, int M, int N)
{
    Node *curr = head, *t;
    int count;

    while (curr)
    {

        for (count = 1; count < M &&
                        curr != NULL;
             count++)
            curr = curr->next;

        if (curr == NULL)
            return;

        t = curr->next;
        for (count = 1; count <= N && t != NULL; count++)
        {
            Node *temp = t;
            t = t->next;
            free(temp);
        }

        curr->next = t;

        curr = t;
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif

    Node *head = takeInput();

    //cout << findmindnode(head)->data << endl;
    skipmdeleten(head, 1, 0);
    print(head);
}
