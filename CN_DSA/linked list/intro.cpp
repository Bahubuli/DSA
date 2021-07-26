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
            Node n1(3);
            Node n2(5);
            Node n3(6);
            Node n4(8);
            Node n5(23);

            Node *head = &n1;

            n1.next = &n2;
            n2.next = &n3;
            n3.next = &n4;
            n4.next = &n5;

            print(head);
}

    // cout << n1.data << " " << n2.data << endl;

    // //Dynamically
    // Node *n3 = new Node(10);
    // Node *n4 = new Node(30);

    // n3->next = n4;
