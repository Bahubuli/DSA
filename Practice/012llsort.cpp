// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate1(Node *head)
    {

        Node *zp = NULL;
        Node *op = NULL;
        Node *tp = NULL;
        Node *prev = NULL;
        Node *nxt = head;
        int gotz = 0, goton = 0, gotto = 0;

        while(nxt!=NULL)
        {
            if(nxt->data==0 && gotz==0)
            {
                zp = nxt;
                gotz = 1;
                cout << "this is 1" << endl;
            }
            if (nxt->data == 1 && goton == 0)
            {
                op = nxt;
                goton = 1;
                cout << "+++++" << endl;
            }
            if (nxt->data == 2 && gotto == 0)
            {
                cout << "this is 3" << endl;
                tp = nxt;
                gotto = 1;
            }
            prev = nxt;
            nxt = nxt->next;
            if(gotto==1 && goton==1 && gotz==1)
                break;
        }

        cout << zp->data << endl;
        cout << op->data << endl;
        cout << tp->data << endl;
        Node *temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        temp = head;

        return head;
    }
    Node *segregate(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *zp = new Node(-1), *op = new Node(-1), *tp = new Node(-1);
        zp->next = op->next = tp->next = NULL;

        Node *one = op;
        Node *two = tp;
        Node *zero = zp;

        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else
            {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        zero->next = (op->next) ? (op->next) : tp->next;
        one->next = tp->next;
        two->next = NULL;
        head = zp->next;


        return head;
    }
};

// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1)
{
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main()
{

    int n;


        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);


    return 0;
} // } Driver Code Ends
