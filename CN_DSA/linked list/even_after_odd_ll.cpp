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


void printll(Node * head)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
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

void eliminatedups(Node *temp)
{

    while(temp->next!=NULL)
    {

        Node *temp2=NULL;

        if(temp->data==temp->next->data)
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
    if(temp==NULL)
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

    while(nxt!=NULL)
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

bool ispalindromell(Node *head)
{
    //edge cases
    if(head->next==NULL)
        return true;
    if(head->data==head->next->data and head->next->next==NULL)
        return true;
    if(head->next->next==NULL and head->data !=head->next->data)
        return false;


    Node *mid = findmindnode(head);
    Node* rmid = reversell(mid);
    mid = rmid;
    Node *temp = head;
    while (rmid != NULL and temp != NULL and rmid->data == temp->data)
    {
        //cout << temp->data << " " << rmid->data << endl;
        temp = temp->next;
        rmid = rmid->next;
    }
    mid = reversell(mid);

    if(temp==NULL or rmid ==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }

}

Node *evenafterodd(Node *head)
{
    Node *even;
    Node *odd;

    if(head->data%2==0)
    {
        even = head;
        while(even->next->data%2==0)
        {
            if(even->next->next==NULL)
                return head;
            even = even->next;
        }
        odd = even->next;
        Node *oddhead = odd;

        while(odd->next!=NULL)
        {
            if(odd->next->data%2!=0)
                odd = odd->next;
            else
            {
                Node *temp = odd->next;
                odd->next = odd->next->next;
                temp->next = oddhead;
                even->next = temp;
                even = even->next;
            }

        }
        Node *temp = even->next;
        even->next = NULL;
        odd->next = head;
        head = temp;
    }


    else
    {
        odd = head;
        while (odd->next->data % 2 != 0)
        {
            if(odd->next->next==NULL)
                return head;
            odd = odd->next;
        }
        even = odd->next;

        Node *evenhead = even;

        while(even->next!=NULL)
        {
            if(even->next->data%2==0)
                even = even->next;
            else
            {
                Node *temp = even->next;
                even->next = even->next->next;
                temp->next = evenhead;
                odd->next = temp;
                odd = odd->next;
            }

        }

    }


    return head;
}

    int main()
    {

        Node *head = takeInput();

        //cout << findmindnode(head)->data << endl;
        head = evenafterodd(head);
        printll(head);
}
