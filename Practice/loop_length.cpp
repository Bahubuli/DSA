// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node *head);

int main()
{
    int t;

        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        cout << countNodesinLoop(head) << endl;

    return 0;
}
// } Driver Code Ends

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{

    int l = 0;
    Node *p1 = head;
    Node *p2 = head->next;
    while (p1 != p2)
    {
        if (p2 == NULL || p2->next == NULL)
            return 0;

        p1 = p1->next;
        p2 = p2->next->next;
    }
    p1 = head;
    while(p1!=p2->next)
    {
        cout << "s loop " << endl;
        p1 = p1->next;
        p2 = p2->next;
    }
   Node * temp = p2->next;
   l++;
   while(temp!=p2)
   {
       temp = temp->next;
       l++;
   }
   return l;
}
