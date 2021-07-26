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
        cout << head->data << endl;
        head = head->next;
    }
}

int main()

{
    Node *head = takeInput();
    print(head);

    // Node n1(3);
    // Node n2(5);
    // Node n3(6);
    // Node n4(8);
    // Node n5(23);

    // Node *head = &n1;

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // print(head);
}
